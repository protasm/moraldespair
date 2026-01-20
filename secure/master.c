#pragma strong_types

/*
** The master bridges the gamedriver and the mudlib, translating driver calls
** into mudlib behavior. Driver calls to the master are wrapped in an implicit
** catch() to prevent unhandled errors from escaping.
**
** The master loads before any other object. It must not inherit other objects
** because many files assume the master already exists, and the compiler cannot
** resolve include paths at that stage unless they are absolute.
*/

#include "/sys/wizlist.h"
#include "/sys/driver_hook.h"
#include "/sys/objectinfo.h"
#include "/sys/functionlist.h"
#include "/sys/erq.h"
#include "/sys/object_info.h"

#define INIT_FILE "/room/init_file"
#define BACKBONE_WIZINFO_SIZE 5
#define SIMUL_EFUN_FILE "secure/simul_efun"
#define SPARE_SIMUL_EFUN_FILE "secure/spare_simul_efun"

#define ADD_SLASH(p) "/"+p
#define GETUID(p) getuid(p)

#if defined(__TLS__) && defined(TLS_PORT)
#include "/sys/interactive_info.h"
#endif

void save_wiz_file(); // forward declaration
int query_player_level (string what); // forward declaration

//===========================================================================
// Compatibility-mode helper functions.
//
// These functions adapt efuns that behave differently in compat and plain
// modes. They mirror a subset of the helpers defined in simul_efun.c.
//===========================================================================

//---------------------------------------------------------------------------
string object_name(object ob) {
  string rc;

  rc = efun::object_name(ob);

  return stringp(rc) ? rc[1..] : 0;
}

//===========================================================================
//  Driver hooks
//
// These functions are installed as driver hooks to handle low-level mudlib
// behavior during runtime.
//===========================================================================

//---------------------------------------------------------------------------
static string _include_dirs_hook (string include_name, string current_file) {
  // Resolve an include name to a full pathname.
  //
  // Argument:
  //   include_name: The name provided in the #include <...> directive.
  //   current_file: The file currently being compiled.
  //
  // Result:
  //   The full path to the include file, or 0 if it cannot be found.
  //
  // If include_name is not found verbatim, the function searches /room, /sys,
  // and /obj (in that order), returning the first match it finds.

  string name, part;
  int pos;

  if (file_size(ADD_SLASH(include_name)) >= 0)
    return include_name;

  name = "room/"+include_name;

  if (file_size(ADD_SLASH(name)) >= 0)
    return name;

  name = "sys/"+include_name;

  if (file_size(ADD_SLASH(name)) >= 0)
    return name;

  name = "obj/"+include_name;

  if (file_size(ADD_SLASH(name)) >= 0)
    return name;

  return 0;
}


//---------------------------------------------------------------------------
static void _move_hook_fun (object item, object dest) {
  // Move an object into its destination while honoring init() semantics.
  //
  // Argument:
  //   item: The object to move.
  //   dest: The destination object.
  //
  // The function validates the move (existence, environment changes, and
  // legality) and enforces the init() protocol required for add_action().

  object *others;
  object env;
  int i;
  string name;

  /* PLAIN:
  if (item != this_object)
    raise_error("Illegal to move other object than this_object()\n");
  */

  if (living(item) && environment(item)) {
    name = object_info(item, OI_ONCE_INTERACTIVE)
      ? item->query_real_name()
      : object_name(item);
    /* PLAIN: exit() must be invoked explicitly in compat mode. */
    efun::set_this_player(item);
    env = environment(item);
    env->exit(item);

    if (!item)
      raise_error(sprintf("%O->exit() destructed item %s before move.\n",
        env, name));
  } else
    name = object_name(item);

  /* Perform the actual move. */

  efun::set_environment(item, dest);

  /* Moving a living object triggers init() in the new environment. */
  if (living(item)) {
    efun::set_this_player(item);
    dest->init();
    
    if (!item)
      raise_error(sprintf("%O->init() destructed moved item %s\n", dest, name));
    
    if (environment(item) != dest)
      return;
  }

  /* Call item->init() once per living in the destination, if still present. */
  others = all_inventory(dest) - ({ item });
  foreach (object obj : others) {
    if (living(obj) && environment(obj) == environment(item)) {
      efun::set_this_player(obj);
      item->init();
    }

    if (!item)
      raise_error(sprintf("item->init() for %O destructed moved item %s\n",
        obj, name));
  }

  /* Call init() on each object, if the item has not moved away. */
  if (living(item)) {
    foreach (object obj : others) {
      efun::set_this_player(item); // Ensure the mover is current.
      if (environment(obj) == environment(item))
        obj->init();
    }

  }

  /* If the destination is living, call item->init() for it too. */
  if (living(dest) && item && environment(item) == dest) {
    efun::set_this_player(dest);
    item->init();
  }

}

//---------------------------------------------------------------------------
static string _auto_include_hook (string base_file, string current_file, int sys_include) {
  // Return any automatic include text for a compiled object.
  //
  // Argument:
  //   base_file: The file being compiled.
  //   current_file: When handling #include statements, the file being included.
  //   sys_include: 1 when <current_file> is a system include.

  // Skip when processing an explicit include.
  if (current_file)
    return 0;

  // Inject the light inheritance into most objects, excluding core ones.
  if (base_file[0] != '/')
    base_file = "/" + base_file;

  if (member((["/obj/light.c", "/secure/simul_efun.c",
    "/secure/spare_simul_efun.c", "/secure/master.c"]), base_file))
    return 0;


  return "virtual inherit \"/obj/light\";\n";
}


//---------------------------------------------------------------------------
static mixed _load_uids_fun (mixed object_name, object prev) {
  // Provide uids for a freshly loaded object.
  //
  // Argument:
  //   object_name: Name of the object being loaded.
  //   prev       : The loading object.
  //
  // Result:
  //   The uid to assign. For /players/<name>/... objects this is "<name>";
  //   everything else returns 1, which maps to the backbone uid.
  //
  // In general, the function can return (<num> is a non-zero number):
  //   "<uid>"                     -> uid = "<uid>", euid = "<uid>"
  //   ({ "<uid>", "<euid>" })     -> uid = "<uid>", euid = "<euid>"
  //   ({ "<uid>", not-a-string }) -> uid = "<uid>", euid = 0
  //
  // If strict-euids is not set, these results are also valid:
  //   <num>                       -> uid = 0, euid = 0
  //   ({ <num>, "<euid>" })       -> uid = 0, euid = "<euid>"
  //   ({ <num>, not-a-string })   -> uid = 0, euid = 0

  string *parts;

  parts = explode(object_name, "/");

  if (sizeof(parts) > 2 && parts[0] == "players")
    return parts[1];

  return 1;
}

#if 0
// PLAIN: The OSB fragment gives backbone objects (/obj, /room) the loader's
// uid, while other objects keep their usual uid but a 0 euid. The practical
// effect is that a wizard's own objects load with a valid euid, while other
// users' objects load with euid 0.

{
  string creator_name;

  creator_name = get_wiz_name(object_name);
  if (prev && creator_name == getuid(prev))
    return geteuid(prev);
  if (prev && creator_name == get_bb_uid())
    return geteuid(prev);

  return ({ creator_name, 1 });
}
#endif

//---------------------------------------------------------------------------
static mixed _clone_uids_fun (object blueprint, string new_name, object prev) {
  // Provide uids for a freshly cloned object.
  //
  // Argument:
  //   blueprint: The cloned blueprint.
  //   new_name : The new object's name.
  //   prev     : The cloning object.
  //
  // Result:
  //   The uids to assign. Prefer the blueprint uid, then the previous object's
  //   uid, and finally 1.
  //
  // Possible results match those described for _load_uids_fun().

  string creator_name;

  return GETUID(blueprint) || GETUID(prev) || 1;
}

#if 0
// PLAIN: The OSB fragment gives backbone objects (/obj, /room) the cloner's
// uid, while other objects keep their usual uid but a 0 euid. The practical
// effect is that a wizard's own objects clone with a valid euid, while other
// users' objects clone with euid 0.

{
  string creator_name;

  creator_name = get_wiz_name(new_name);
  if (prev && creator_name == getuid(prev))
    return geteuid(prev);
  if (prev && creator_name == get_bb_uid())
    return geteuid(prev);

  return ({ creator_name, 1 });
}
#endif

//---------------------------------------------------------------------------
static void _create_fun (object ob, object creator) {
  // Initialize a freshly created object by calling ob->create().
  //
  // Argument:
  //   ob: The created object.
  //   creator: The creator object.
  //

  closure fun;
  // Create a non-alien create() closure if it exists.
  set_this_object(ob);
  fun = symbol_function("create", ob);

  // Invoke create() with the creator as the previous object.
  set_this_object(creator);
  if (fun)
    funcall(fun);
}

//===========================================================================
//  Initialization
//
// These functions run after (re)loading the master to establish the
// foundational driver settings.
//
// LPMud startup follows this sequence:
//   - The gamedriver evaluates the commandline options and initializes
//     itself.
//   - The master is loaded, but since the driverhooks are not set yet,
//     no standard initialization lfun is called.
//   - get_master_uid() is called. If the result is valid, it becomes the
//     master's uid and euid.
//   - inaugurate_master() is called.
//   - flag() is called for each given '-f' commandline option.
//   - get_simul_efun() is called.
//   - the WIZLIST is read in.
//   - epilog() is called. If it returns an array of strings, each entry is
//     passed to preload().
//     Traditionally, these strings are the filenames of the objects to
//     preload, read from /room/init_file.
//   - The gamedriver sets up the IP communication and enters the backend
//     loop.
//
// If the master is reloaded during the game, the sequence is:
//   - The master is loaded, and its initialization lfun is called according
//     to the settings of the driverhooks (if set).
//   - Any auto-include string and all driverhooks are cleared.
//   - get_master_uid() is called. If the result is valid, it becomes the
//     master's uid and euid.
//   - inaugurate_master() is called.
//
// If the master was destructed but cannot be reloaded, the old master
// object may be reactivated. In that case:
//   - reactivate_destructed_master() is called.
//   - inaugurate_master() is called.
//===========================================================================

//---------------------------------------------------------------------------
// Initialization behavior for the master object.
//
// Because object-initialization lfuns are defined by driver hooks, and those
// hooks are cleared before a master (re)load, inaugurate_master() is the
// first reliable entry point. Earlier calls are unsafe because the master
// is not recognized yet and important systems are unavailable.
//
// Which lfun resets the master during runtime depends on driverhook settings.
// Use reset sparingly and intentionally.

//---------------------------------------------------------------------------
void inaugurate_master (int arg) {
  // Perform mudlib-specific setup for the master.
  //
  // Argument:
  //   arg: 0 if the mud just started.
  //        1 if the master is a reactivated destructed instance.
  //        2 if the master is reactivated and lost its variables.
  //        3 if the master was just reloaded.
  //
  // This function is called whenever the master becomes fully operational
  // after (re)loading (it is now recognized as _the_ master).
  // This does not imply that the game is up and running.
  //
  // This function must at least install driver hooks. Mudwho and wizlist
  // handling are also initialized here.
  //
  // Perform any additional setup as needed, such as setting a master euid.

  if (!arg) {
    if (previous_object() && previous_object() != this_object())
      return;
    set_extra_wizinfo(0, allocate(BACKBONE_WIZINFO_SIZE));
  }

  // Schedule periodic wizlist decay.
  if (find_call_out("wiz_decay") < 0)
    call_out("wiz_decay", 3600);

  set_driver_hook(
    H_MOVE_OBJECT0,
    unbound_lambda(
      ({'item, 'dest}),
      ({#'_move_hook_fun, 'item, 'dest})
    )
  );
  set_driver_hook(
    H_LOAD_UIDS,
    unbound_lambda(
      ({'object_name}),
      ({#'_load_uids_fun, 'object_name, ({#'previous_object})})
    )
  );
  set_driver_hook(
    H_CLONE_UIDS,
    unbound_lambda(
      ({ /* object */ 'blueprint, 'new_name}),
      ({#'_clone_uids_fun, 'blueprint, 'new_name, ({#'previous_object})})
    )
  );
  /* Simulate compat-mode behavior by calling reset() with an argument:
  * 0 when creating, 1 when resetting.
  *
  * Non-compat mudlibs usually specify "create" for H_CREATE_* hooks and
  * "reset" for the H_RESET hook.
  */
  set_driver_hook(
    H_CREATE_SUPER,
    unbound_lambda(
      ({ 'ob }),
      ({#'_create_fun, 'ob, ({#'this_object})})
    )
  );
  set_driver_hook(
    H_CREATE_OB,
    unbound_lambda(
      ({ 'ob }),
      ({#'_create_fun, 'ob, ({#'this_object})})
    )
  );
  set_driver_hook(
    H_CREATE_CLONE,
    unbound_lambda(
      ({ 'ob }),
      ({#'_create_fun, 'ob, ({#'this_object})})
    )
  );
  set_driver_hook(
    H_RESET,
    unbound_lambda(
      0,
      ({#'funcall, ({#'symbol_function, "reset", ({#'this_object})}), 1})
    )
  );
  set_driver_hook(H_CLEAN_UP, "clean_up");
  set_driver_hook(
    H_MODIFY_COMMAND,
    ([ "e":"east", "w":"west", "s":"south", "n":"north",
      "d":"down", "u":"up", "nw":"northwest", "ne":"northeast",
      "sw":"southwest", "se":"southeast" ])
  );
  set_driver_hook(H_MODIFY_COMMAND_FNAME, "modify_command");
  set_driver_hook(H_NOTIFY_FAIL, "What?\n");
  set_driver_hook(H_INCLUDE_DIRS, #'_include_dirs_hook);
  set_driver_hook(H_AUTO_INCLUDE, #'_auto_include_hook);
}

//---------------------------------------------------------------------------
mixed get_master_uid () {
  // Return the uid/euid value for a (re)loaded master.
  //
  // Possible results include:
  //
  //     "<uid"> -> uid = "<uid>", euid = "<euid>"
  //
  // In non-strict-euids mode, additional results are allowed:
  //
  //     0       -> uid = 0, euid = 0
  //     <num>   -> uid = 'default', euid = 0
  //
  // If your uids are filename-based, return a value that cannot appear in
  // a legal filename. OSB uses "ze/us" for this purpose.


  return 1;
}

//---------------------------------------------------------------------------
void flag (string arg) {
  // Handle '-f' command-line options passed to the driver.
  //
  // Arguments:
  //   arg: The argument string from '-f<arg>'. Multiple '-f' options are
  //        delivered sequentially.
  //
  // Supported commands:
  //   '-fcall <ob> <fun> <arg>': call <ob>-><fun>(<arg>).
  //   '-fshutdown': shut down the game immediately.
  //
  // For example: 'parse "-fcall foo bar Yow!" -fshutdown' executes the
  // call before shutting down.

  string obj, fun, rest;

  if (arg == "shutdown") {
    shutdown();
    return;
  }

  if (sscanf(arg, "call %s %s %s", obj, fun, rest) >= 2) {
    write(obj+"->"+fun+"(\""+rest+"\") = ");
    write(call_other(obj, fun, rest));
    write("\n");
    return;
  }

  write("master: Unknown flag "+arg+"\n");
}

//---------------------------------------------------------------------------
static mixed current_time;
/* Track epilog start time for preload timing output. */

string *epilog (int eflag) {
  // Perform final setup before opening the game to players.
  //
  // Arguments:
  //   eflag: The number of '-e' options given to the parser (usually 0 or 1).
  //
  // Result:
  //   An array of object filenames to preload, typically read from
  //   /room/init_file. Any other result means "no preload."
  //
  //   Each entry is passed to preload() in order.


  if (eflag)
    return ({});

  debug_message(sprintf("Loading init file %s\n", INIT_FILE));
  current_time = rusage();
  current_time = current_time[0] + current_time[1];

  return explode(read_file(INIT_FILE), "\n");
}

//---------------------------------------------------------------------------
void preload (string file) {
  // Preload a single object entry.
  //
  // Arguments:
  //   file: The filename to preload, as returned by epilog().
  //
  // epilog()/preload() should filter comments and blank lines. For each
  // entry, load_object(file) is sufficient, but consider catch() to avoid
  // blocking and consider lowering the master's euid for safety.
  //
  // Other behaviors are possible; preloading is just the traditional use.

  int last_time;

  if (sizeof(file) && file[0] != '#') {
    last_time = current_time;
    debug_message(sprintf("Preloading file: %s", file));
    load_object(file);
    current_time = rusage();
    current_time = current_time[0] + current_time[1];
    debug_message(sprintf(" %.2f\n", (current_time - last_time) / 1000.0));
  }

}

//---------------------------------------------------------------------------
//void external_master_reload ()

// Handle a master reload initiated by SIGUSR1.
//
// The driver calls this after reloading the master in response to SIGUSR1.
// It runs after inaugurate_master(). Add additional handling here if needed.


//---------------------------------------------------------------------------
//void reactivate_destructed_master (int removed)

// Reactivate a destructed master object.
//
// Arguments:
//   removed: True if the master was already on the destructed list.
//
// This function is invoked when the driver cannot load a new master.
// It must reinitialize all state required to continue operation.


//---------------------------------------------------------------------------
mixed get_simul_efun () {
  // Load simul_efun objects and return their paths.
  //
  // Result:
  //   Either a single string containing the simul_efun object_name(), or an
  //   array of strings that begins with that object_name(). Return 0 to
  //   disable simul_efuns.
  //
  // The objects must be loaded by this function.
  //
  // When returning an array, the first entry is the primary simul_efun, and
  // subsequent entries are backups used when older code calls removed efuns.
  // This allows stale code to keep running while efuns are retired.
  //
  // If the mudlib requires simul_efuns and none load successfully, the game
  // should shut down immediately.

  mixed error;
  object ob;

  error = catch(ob = load_object(SIMUL_EFUN_FILE));
  if (!error) {
    ob->start_simul_efun();
    return SIMUL_EFUN_FILE;
  }

  efun::write("Failed to load " + SIMUL_EFUN_FILE + ": "+error);
  error = catch(ob = load_object(SPARE_SIMUL_EFUN_FILE));
  if (!error) {
    ob->start_simul_efun();
    return SPARE_SIMUL_EFUN_FILE;
  }

  efun::write("Failed to load " + SPARE_SIMUL_EFUN_FILE + ": "+error);
  efun::shutdown();

  return 0;
}

//===========================================================================
//  Handling of player connections
//
// See also valid_exec().
//===========================================================================

//---------------------------------------------------------------------------
object connect () {
  // Handle an incoming connection request.
  //
  // Result:
  //   A login object to bind the connection to (a clone of secure/player.c).
  //
  // The connection is not bound at this point.
  //
  // The driver calls logon() on the login object after binding the
  // connection. logon() must return non-zero to succeed.

  object ob;
#if defined(__TLS__) && defined(TLS_PORT)
  int mud_port;
#endif

  ob = clone_object("secure/player");
  if (!ob)
    return 0;

#if defined(__TLS__) && defined(TLS_PORT)
  // Determine which port the interactive connected to.
  mud_port = efun::interactive_info(this_interactive(), II_MUD_PORT);
  // If it is TLS_PORT, attempt to initialize TLS.
  if (mud_port == TLS_PORT) {
    // Reject the connection if TLS is unavailable.
    if (!tls_available())
      return 0;
    tls_init_connection(this_object(), "tls_logon", ob);
  }

#endif

  return ob;
}

//---------------------------------------------------------------------------
void disconnect (object obj) {
  // Handle the loss of an IP connection.
  //
  // Argument:
  //   obj: The (formerly) interactive object (player).
  //
  // This is called by the gamedriver when the IP connection is removed,
  // either due to netdeath or because of exec() or remove_interactive().
  // The connection will be unbound upon return from this call.

}

//---------------------------------------------------------------------------
void remove_player (object player) {
  // Remove a player object from the game.
  //
  // Argument:
  //   player: The player object to be removed.
  //
  // The gamedriver calls this during shutdown to politely remove players.
  // If this function fails to quit/destruct a player, the driver will
  // destruct the object forcefully.
  //
  // Note: This function must not cause runtime errors.

  catch(player->quit());
  if (player)
    destruct(player);
}

//---------------------------------------------------------------------------
void stale_erq (closure callback) {
  // Handle a lost erq daemon connection.
  //
  // Argument:
  //   callback: The callback closure associated with the erq request.
  //
  // If the erq connection dies prematurely, the driver calls this lfun for
  // every pending request. This function should notify the originating
  // object that the answer will never arrive.
  //
  // In this mudlib, we simply reattach the default erq.

  attach_erq_demon("", 0);
}


//===========================================================================
//  Runtime Support
//
// Various functions used to implement advanced runtime features.
//===========================================================================

//---------------------------------------------------------------------------
object compile_object (string filename) {
  // Compile a virtual object.
  //
  // Arguments:
  //   previous_object(): The object requesting the virtual object.
  //   filename         : The requested filename for the virtual object.
  //
  // Result:
  //   The object to serve as the requested virtual object, or 0.
  //
  // This function is called if the compiler cannot find a filename to
  // compile. The master may return an alternative object that will serve as
  // if it were compiled from <filename>.
  // If the master returns 0, the usual 'Could not load'-error will occur.
  //
  // The function tries several possible VMasters in sequence, calling
  // compile_object(<filename>) in each of them until one returns
  // an object. The objects tried in order (if existing) are:
  //  1. <path_of_filename>/vmaster.c
  //  2  <path_of_filename>.c
  //    In both cases, only the basename part of <filename> is passed
  //    to compile_object().

  object obj, room;
  mixed vmaster;
  string filepath;

  if (filename[0] != '/') filename = "/"+filename;
  filepath = implode(explode(filename,"/")[0..<2],"/");
  vmaster = filepath+"/vmaster";
  if (0 <= file_size(vmaster+".c"))
    room = ({object})vmaster->compile_object(explode(filename,"/")[<1]);
  if (!room && 0 <= file_size(filepath+".c"))
    room = ({object})filepath->compile_object(explode(filename,"/")[<1]);

  return room;
}


//---------------------------------------------------------------------------
string get_wiz_name (string file) {
  // Arguments:
  //   file: The name of the file in question.
  //
  // Result:
  //   The name of the file's author (or 0 if there is none).
  //
  // This function is called when maintaining the wiz-list to attribute
  // errors to the correct wizard.

  string name, rest;

  if (sscanf(file, "players/%s/%s", name, rest) == 2)
    return name;

  return 0;
}

//---------------------------------------------------------------------------
// string printf_obj_name (object obj)

// Return a printable name for an object.
//
// Arguments:
//   obj: The object whose name is being printed.
//
// Result:
//   A string with the object's name, or 0.
//
// This function is called by sprintf() to print a meaningful name
// in addition to the normal object_name().
// If this function returns a string, the object will be printed
// as "<obj_name> (<printf_obj_name>)".


//---------------------------------------------------------------------------
void destruct_environment_of(object ob) {
  /* When an object is destructed, this function runs for every item in the
  * room, giving us a chance to rescue any players.
  */

  mixed error;

  if (!interactive(ob))
    return;
  tell_object(ob, "Everything you see is disolved. Luckily, you are transported somewhere...\n");

  if (error = catch(ob->move_player("is transfered#domain/original/void"))) {
    write(error);
    if (error = catch(move_object(ob, "domain/original/void"))) {
      object new_player;

      write(error);
      new_player = clone_object("secure/player");
      if (!function_exists("replace_player", new_player)) {
        destruct(new_player);
        return;
      }

      exec(new_player, ob);
      if (error = catch(new_player->replace_player(ob, "domain/original/void")))
        write(error);
    }

  }

}

//---------------------------------------------------------------------------
void move_or_destruct(object what, object to) {
  /* Move <what> into <to>, or destruct <what> if that is not possible.
  *
  * An error in this function can be very nasty. Note that unlimited recursion
  * is likely to cause errors when environments are deeply nested.
  */

  if (!catch(what->move(to, 1)))
    return;

  /*
  * If the move failed, destroy the object.
  */
  destruct(what);
}

//---------------------------------------------------------------------------
mixed prepare_destruct (object ob) {
  // Prepare the destruction of the given object.
  //
  // Argument:
  //   obj : The object to destruct.
  //
  // Result:
  //   Return 0 if the object is ready for destruction, any other value
  //   will abort the attempt.
  //   If a string is returned, an error with the string as message will
  //   be issued.
  //
  // The gamedriver calls this function whenever an object shall be destructed.
  // It expects, that this function cleans the inventory of the object, or
  // the destruct will fail.
  // Furthermore, the function could notify the former inventory objects that
  // their holder is under destruction (useful to move players out of rooms which
  // are updated); and it could announce mudwide the destruction(quitting) of
  // players.

  object super;
  int i;
  object sh, next;

  /* Remove all pending shadows */
  if (!object_info(ob, OI_SHADOW_PREV))
    for (sh = object_info(ob, OI_SHADOW_NEXT); sh; sh = next) {
    next = efun::object_info(sh, OI_SHADOW_NEXT);
    funcall(bind_lambda(#'unshadow, sh)); /* avoid deep recursion */
    destruct(sh);
  }

  super = environment(ob);

  if (!super) {
    object item;

    while ( item = first_inventory(ob) ) {
      destruct_environment_of(item);
      if (item && environment(item) == ob) destruct(item);
    }

  } else {
    while ( first_inventory(ob) )
      move_or_destruct(first_inventory(ob), super);
  }

  if (interactive(ob))
    disconnect(ob);

  return 0; /* success */
}


//---------------------------------------------------------------------------
//void quota_demon (void)

// Handle quotas in times of memory shortage.
//
// This function is called during the final phase of a garbage collection if
// the reserved user area couldn't be reallocated. This function (or a called
// demon) has now the opportunity to remove some (still active) objects from
// the game. If this does not free enough memory to reallocate the user
// reserve, slow_shut_down() will be called to start Armageddon.
//
// Note: Up to now, the wizlist lacks various informations needed to detect
//   the memory-hungriest wizards.


//---------------------------------------------------------------------------
//void receive_imp (string host, string msg, int port)

// Handle a received IMP message.
//
// Arguments:
//   host: Name of the host the message comes from.
//   msg : The received message.
//   port: the port number from which the message was sent.
//
// This function is called for every message received on the IMP port.


//---------------------------------------------------------------------------
void slow_shut_down (int minutes) {
  // Schedule a shutdown for the near future.
  //
  // Argument:
  //   minutes: The desired time in minutes till the shutdown:
  //             6, if just the user reserve has been put into use;
  //             1, if the (smaller) system or even the master reserve
  //                has been put into use as well.
  //
  // The gamedriver calls this function when it runs low on memory.
  // At this time, it has freed its reserve, but since it won't last long,
  // the games needs to be shut down. Don't take the 'minutes' as granted
  // remaining uptime, just deduce the urgency of the shutdown from it.
  // The delay is to give the players the opportunity to finish quests,
  // sell their stuff, etc.
  // It is possible that the driver may reallocate some memory after the
  // function has been called, and then run again into a low memory situation,
  // calling this function again.
  //
  // In our case, this function loads an 'Armageddon' object and tells
  // it what to do. It is the Armageddon object then which performs
  // the shutdown.
  //
  // Technical:
  //   The memory handling of the gamedriver includes three reserved areas:
  //   user, system and master. All three are there to insure that the game
  //   shuts down gracefully when the memory runs out: the user area to give
  //   the players time to quit normally, the others to enable emergency-logouts
  //   when the user reserve is used up as well.
  //   The areas are allocated at start of the gamedriver, and released when
  //   no more memory could be obtained from the host. In such a case, one
  //   of the remaining areas is freed (so the game can continue a short
  //   while) and a garbagecollection is initiated.
  //   If the garbagecollection recycles enough memory (either true garbage
  //   or by the aid of the quota_demon) to reallocate the areas, all is
  //   fine, else the game is shut down by a call to this function.

  filter(users(), #'tell_object,
  "Game driver shouts: The memory is getting low !\n");
  "obj/shut"->shut(minutes);
}

//---------------------------------------------------------------------------
varargs void notify_shutdown (string crash_reason) {
  // Notify the master about an immediate shutdown. If <crash_reason> is 0,
  // it is a normal shutdown, otherwise it is a crash and <crash_reason>
  // gives a hint at the reason.
  //
  // The function has the opportunity to perform any cleanup operation, like
  // informing the mudwho server that the mud is down. This can not be done
  // when remove_player() is called because the udp connectivity is already
  // gone then.
  //
  // If the gamedriver shuts down normally , this is the last function called
  // before the mud shuts down the udp connections and the accepting socket
  // for new players.
  //
  // If the gamedriver crashes, this is the last function called before the
  // mud attempts to dump core and exit. WARNING: Since the driver is in
  // an unstable state, this function may not be able to run to completion!
  // The following crash reasons are defined:
  //   "Fatal Error": an internal sanity check failed.

  if (previous_object() && previous_object() != this_object())
    return;
  if (!crash_reason)
    filter(users(), #'tell_object,
  "Game driver shouts: LPmud shutting down immediately.\n");
  else
    filter(users(), #'tell_object,
  "Game driver shouts: PANIC! "+ crash_reason+"!\n");
  save_wiz_file();
}

//===========================================================================
//  Error Handling
//
//===========================================================================

//---------------------------------------------------------------------------
void dangling_lfun_closure () {
  // Handle a dangling lfun closure.
  //
  // This is called when the driver executes a closure that references a
  // vanished lfun. The correct response is to raise a runtime error.
  //
  // Technical:
  //   When programs are replaced (see efun replace_program()), any existing
  //   lambda closures are adjusted to the new environment. If a closure uses
  //   an lfun that vanished in the replacement process,
  //   the reference to this lfun is replaced by a reference to this function.
  //   The error will then occur when the adjusted lambda executes the missing
  //   call.
  //   There are two reasons for delayed handling. First, program replacement
  //   and closure adjustment happen at the end of a backend cycle, outside of
  //   any execution thread, so no one would observe the error immediately.
  //   Second, smart closures might recognize program replacement
  //   and skip the call to the vanished lfun.

  raise_error("dangling lfun closure\n");
}

//---------------------------------------------------------------------------
void log_error(string file, string err) {
  // Record a compiler-time error.
  //
  // Arguments:
  //   file: The name of the file containing the error (not necessarily an
  //         object file).
  //   err : The error message.
  //
  // The LPC compiler calls this on error. It should log the error and notify
  // the active player if they are a wizard.

  string name;

  name = get_wiz_name(file);
  if (name == 0)
    name = "log";
  write_file("/log/"+name, err);
}

//---------------------------------------------------------------------------
mixed heart_beat_error(object culprit, string err,
string prg, string curobj, int line) {
  // Report an error in the heart_beat() function.
  //
  // Arguments:
  //   culprit: The object which lost the heart_beat.
  //   err    : The error message.
  //   prg    : The executed program (might be 0).
  //   curobj : The object causing the error (might be 0).
  //   line   : The line number where the error occurred (might be 0).
  //
  // Result:
  //   Return anything != 0 to restart the heart_beat in culprit.
  //
  // This function reports an error in culprit->heart_beat(). The heartbeat is
  // already turned off. Players should at least see a "You have no heartbeat!"
  // message; more advanced handling could destruct the offending object and
  // allow the heartbeat to restart.
  //
  // Note that <prg> denotes the program actually executed (which might be
  // inherited one) whereas <curobj> is just the offending object.

  if ( interactive(culprit) )
    tell_object(
    culprit,
    "Game driver tells you: You have no heart beat !\n"
    );

  return 0; /* Don't restart */
}

//---------------------------------------------------------------------------
void runtime_error( string err, string prg, string curobj, int line
, mixed culprit) {
  // Report a runtime error.
  //
  // Arguments:
  //   err    : The error message.
  //   prg    : The executed program.
  //   curobj : The object causing the error.
  //   line   : The line number where the error occurred.
  //   culprit: -1 for runtime errors; the object holding the heart_beat()
  //            function for heartbeat errors.
  //
  // This function reports a runtime error to the active user or handles a
  // runtime error that occurred during heart_beat() for <culprit>.
  //
  // For normal runtime errors, wizards should see the full message and source
  // line. Players should see a restrained message and the error may be
  // announced to online wizards.
  //
  // If the error is a heartbeat error, the heartbeat for the offending
  // <culprit> has been turned off. This function should not do much, since
  // heart_beat_error() will be called right after this one.
  //
  // Note that <prg> denotes the program actually executed (which might be
  // inherited) whereas <curobj> is just the offending object for which the
  // program was executed.

  if (this_player() && interactive(this_player()))
    catch( write(
  query_player_level("error messages") ?
  curobj ?
  err +
  "program: " + prg +
  ", object: " + curobj +
  " line " + line + "\n"
  :
  err
  :
  "Your sensitive mind notices a wrongness in the fabric of space.\n"
  ) );
}

//===========================================================================
//  Security and Permissions
//
// Most of these functions guard critical efuns. A common approach is to
// wrap efuns in simul_efuns and reserve real efuns for privileged objects.
//
// See also valid_read() and valid_write().
//===========================================================================

//---------------------------------------------------------------------------
int privilege_violation (string op, mixed who, mixed arg, mixed arg2) {
  // Validate the execution of a privileged operation.
  //
  // Arguments:
  //   op   : The requested operation (see below).
  //   who  : The object requesting the operation (filename or object).
  //   arg  : Additional argument, depending on <op>.
  //   arg2 : Additional argument, depending on <op>.
  //
  // Result:
  //     >0: The caller is allowed for this operation.
  //      0: The caller was probably misled; try to fix the error.
  //   else: A real privilege violation; handle it as an error.
  //
  // Privileged operations include:
  //   attach_erq_demon  : Attach the erq demon to object <arg> with flag <arg2>.
  //   bind_lambda       : Bind a lambda-closure to object <arg>.
  //   call_out_info     : Return an array with all call_out information.
  //   erq               : Send request <arg4> to the erq daemon.
  //   input_to          : Object <who> issues an ignore-bang input_to() for
  //                       commandgiver <arg3>; the exact flags are <arg4>.
  //   nomask simul_efun : Attempt to get an efun <arg> via efun:: when it
  //                       is shadowed by a 'nomask'-type simul_efun.
  //   rename_object     : The current object <who> renames object <arg>
  //                       to name <arg2>.
  //   send_imp          : Send UDP-data to host <arg>.
  //   get_extra_wizinfo : Get the additional wiz-list info for wizard <arg>.
  //   set_extra_wizinfo : Set the additional wiz-list info for wizard <arg>.
  //   set_extra_wizinfo_size : Set the size of the additional wizard info
  //                       in the wiz-list to <arg>.
  //   set_driver_hook   : Set hook <arg> to <arg2>.
  //   limited:          : Execute <arg> with reduced/changed limits.
  //   set_limits        : Set limits to <arg>.
  //   set_this_object   : Set this_object() to <arg>.
  //   shadow_add_action : Add an action to function <arg> from a shadow.
  //   symbol_variable   : Attempt to create a symbol for a hidden variable
  //                       of object <arg> with index <arg2> in the object's
  //                       variable table.
  //   wizlist_info      : Return an array with all wiz-list information.
  //
  // call_out_info can reveal arguments to functions and lambda closures, and
  // read access to closures, mappings, and arrays implies write access and
  // other privileges. wizlist_info() returns extra wizlist data that may
  // include sensitive closures. send_imp() can be abused to interfere with
  // the IMP. The xxx_extra_wizinfo operations are necessary for wizlist
  // maintenance and should be restricted to admins. All other operations
  // are potential sources of security breaches and must be scrutinized.

  /* This object and the simul_efun objects may do everything. */
  if (who == this_object()
    || who == find_object(SIMUL_EFUN_FILE)
    || who == find_object(SPARE_SIMUL_EFUN_FILE))
    return 1;

  switch (op) {
    case "erq":
      switch (arg) {
        case ERQ_RLOOKUP:
          return 1;
        case ERQ_EXECUTE:
        case ERQ_FORK:
        case ERQ_AUTH:
        case ERQ_SPAWN:
        case ERQ_SEND:
        case ERQ_KILL:
        default:
          return -1;
      }

    default:
      return -1; /* Make this violation an error. */
  }

  return 0;
}

//---------------------------------------------------------------------------
int query_allow_shadow (object victim) {
  // Validate a shadowing attempt.
  //
  // Arguments:
  //   previous_object(): The object attempting to shadow.
  //   victim           : The object to be shadowed.
  //
  // Result:
  //   Return 0 to disallow the shadowing, any other value to allow it.
  //   Destructing the shadow or the victim is another way of disallowing.
  //
  // This function asks the victim whether it denies the shadow.

  if (object_info(victim, OINFO_MEMORY)[OIM_NO_SHADOW])
    return 0;

  return !victim->query_prevent_shadow(previous_object());
}

//---------------------------------------------------------------------------
int query_player_level (string what) {
  // Check if the player is high enough level for a requested capability.
  //
  // Argument:
  //   what: The requested capability (see below).
  //
  // Result:
  //   Return 0 to disallow, any other value to allow it.
  //
  // Types asked for so far are:
  //   "error messages": Is the player allowed to see error messages (used
  //                     by the master)?
  //                     (min-level: 20)
  //   "wizard"        : Is the player considered a wizard (used by
  //                     the mudlib)?
  //                     (min-level: 20)

  int level;

  if (this_player() == 0)
    return 0;
  level = ({int})this_player()->query_level();
  switch (what) {
    case "wizard":
      return level >= 20;
    case "error messages":
      return level >= 20;
  }

  return 0;
}

//---------------------------------------------------------------------------
int valid_trace (string what) {
  // Check if the player is allowed to use tracing.
  //
  // Argument:
  //   what: The actual action (see below).
  //
  // Result:
  //   Return 0 to disallow, any other value to allow it.
  //
  // Actions handled so far are:
  //   "trace":       Is the user allowed to use tracing?
  //   "traceprefix": Is the user allowed to set a traceprefix?
  //                  (min-level: 24 for both)

  int level;

  if (this_player() == 0)
    return 0;
  level = ({int})this_player()->query_level();
  switch (what) {
    case "trace":
    case "traceprefix":
      return level >= 24;
  }

  return 0;
}

//---------------------------------------------------------------------------
int valid_exec (string name, object ob, object obfrom) {
  // Validate rebinding an IP connection using exec().
  //
  // Arguments:
  //    name  : The name of the _program_ attempting to rebind the connection.
  //            This is not the object_name() of the object, and has no leading
  //            slash.
  //    ob    : The object to receive the connection.
  //    obfrom: The object giving the connection away.
  //
  // Result:
  //   Return a non-zero number to allow the action; any other value disallows.
  //
  // Only secure/master.c and secure/login.c are allowed to do this.

  switch (name) {
    case "secure/login.c":
    case "secure/master.c":
      if (!interactive(ob))
        return 1;
  }

  return 0;
}

//---------------------------------------------------------------------------
int valid_query_snoop (object obj) {
  // Validate whether query_snoop() may reveal snoopers for an object.
  //
  // Arguments:
  //   previous_object(): the asking object.
  //   obj              : the object which snoopers are to be revealed.
  //
  // Result:
  //   Return a non-zero number to allow the action; any other value disallows.
  //
  // Any true wizard may test for a snoop.

  return this_player()->query_level() >= 22;
}

//---------------------------------------------------------------------------
int valid_snoop (object snoopee, object snooper) {
  // Validate the start or stop of a snoop.
  //
  // Arguments:
  //   snoopee: The victim of the snoop.
  //   snooper: The wannabe snooper, or 0 when stopping a snoop.
  //
  // Result:
  //   Return a non-zero number to allow the action; any other value disallows.
  //
  // The simul_efun object is responsible for starting and stopping snoops.

  /* PLAIN:
  if (!geteuid(previous_object()))
    return 0;
  */
  if (object_name(previous_object()) == get_simul_efun())
    return 1;

  return 0;
}


//===========================================================================
//  Userids and related security
//
// Each object in the mud has a string attribute that determines its rights in
// security-sensitive matters. In compat muds this is the object's "creator";
// in !compat muds it is the object's "userid" ("uid").
//
// "Effective userids" (euid) extend this system to differentiate between an
// object's theoretical permissions (uid) and its current permissions (euid).
//
// The driver implements setting/querying of (e)uids, while the mudlib assigns
// the correct (e)uid to each object and checks them where necessary.
//
// If the driver uses strict euids, loading and cloning require a non-zero
// euid on the initiating object.
//
// The primary use of (e)uids is file access control, but they can also be
// used for identification purposes.
//===========================================================================

//---------------------------------------------------------------------------
// string get_bb_uid()

// Return the string (or 0) to be used as the backbone euid.
// It is used by process_string() only when no this_object() is present.
// If strict-euids is enabled, the function must exist and return a string.

//---------------------------------------------------------------------------
mixed valid_read  (string path, string euid, string fun, object caller) {
  // Validate a file read operation.
  //
  // Arguments:
  //   path   : The (possibly partial) filename given to the operation.
  //   euid   : The euid of the caller (might be 0).
  //   fun    : The name of the operation requested (see below).
  //   caller : The calling object.
  //
  // Result:
  //   The full pathname to operate on, or 0 if the action is not allowed.
  //   Return 1 to indicate that the path can be used unchanged.
  //
  // The final path must not contain spaces or "..".
  //
  // These functions establish file access rights. In this implementation,
  // secure/player->valid_read(<path>) performs most of the work.
  //
  // valid_read() is called for these operations:
  //   ed_start        (when reading a file)
  //   file_size
  //   get_dir
  //   print_file
  //   read_bytes
  //   read_file
  //   restore_object
  //   tail

  string user;

  switch (fun) {
    case "restore_object":
      return 1;
    case "ed_start":
      if (previous_object() && previous_object() != this_player())
        return 0;
      if (!path) {
        /* Request the last error file. */
        mixed *error;

        error = get_error_file(({string})this_player()->query_real_name());
        if (!error || error[3]) {
          write("No error.\n");
          return 0;
        }

        write(error[0][1..]+" line "+error[1]+": "+error[2]+"\n");
        return ADD_SLASH(error[0]);
      }

      if (path[0] != '/')
        path = "/"+path;
    case "read_file":
    case "read_bytes":
    case "file_size":
    case "get_dir":
    case "do_rename":
      if (caller == this_object())
        return 1;
    case "tail":
    case "print_file":
    case "make_path_absolute": /* internal use, see below */
      set_this_object(caller);
      if (this_player() && interactive(this_player())) {
        path = ({string})this_player()->valid_read(path);
        if (!stringp(path)) {
          write("Bad file name.\n");
          return 0;
        }

        return ADD_SLASH(path);
      }

      path = ({string})"secure/player"->valid_read(path);
      if (stringp(path))
        return ADD_SLASH(path);
      return 0;
  }

  /* If no case returned a value or the operation is unrecognized, deny. */

  return 0;
}

//---------------------------------------------------------------------------
mixed valid_write (string path, string euid, string fun, object caller) {
  // Validate a file write operation.
  //
  // Arguments:
  //   path   : The (possibly partial) filename given to the operation.
  //   euid   : The euid of the caller (might be 0).
  //   fun    : The name of the operation requested (see below).
  //   caller : The calling object.
  //
  // Result:
  //   The full pathname to operate on, or 0 if the action is not allowed.
  //   Return 1 to indicate that the path can be used unchanged.
  //
  // The final path must not contain spaces or "..".
  //
  // These functions establish file access rights. In this implementation,
  // secure/player->valid_write(<path>) performs most of the work.
  //
  // valid_write() is called for these operations:
  //   ed_start     (when writing a file)
  //   rename_from  (for each old name of a rename())
  //   rename_to    (for the new name of a rename())
  //   mkdir
  //   save_object
  //   objdump
  //   opcdump
  //   remove_file
  //   rmdir
  //   write_bytes
  //   write_file

  string user;

  if (path[0] == '/' && path != "/")
    path = path[1..];

  switch (fun) {
    case "objdump":
      if (path == "OBJ_DUMP")
        return path;
      return 0;

    case "opcdump":
      if (path == "OPC_DUMP")
        return path;
      return 0;

    case "save_object":
      if (user = GETUID(previous_object())) {
        if (path[0 .. sizeof(user)+7] == "players/" + user
          && sscanf(path, ".%s", user) == 0)
          return ADD_SLASH(path);
      } else {
        user = efun::object_name(previous_object());
#ifndef __COMPAT_MODE__
        user = user[1..];
#endif
        if (user[0..3] == "obj/"
         || user[0..3] == "std/")
          return ADD_SLASH(path);
        if (sizeof(user) > 12
          && user[0..12] == "secure/player"
          && path[0..7] == "players/")
          return ADD_SLASH(path);
      }

      return 0; /* deny access */
    default:
      return 0; /* deny access */
    case "write_file":
      if (caller == this_object())
        return 1;
      if (path[0..3] == "log/"
        && !(sizeof(regexp(({path[4..33]}), "/"))
        || path[4] == '.'
        || sizeof(path) > 34))
        return ADD_SLASH(path);
      break;
    case "ed_start":
      if (path[0] != '/')
        path = "/"+path;
      break;
    case "rename_from":
    case "rename_to":
      if ((efun::object_name(caller) == SIMUL_EFUN_FILE
        || efun::object_name(caller) == SPARE_SIMUL_EFUN_FILE)
        && path[0..3] == "log/"
        && !(sizeof(regexp(({path[4..33]}), "/"))
        || path[4] == '.'
        || sizeof(path) > 34))
        return 1;
    case "mkdir":
    case "rmdir":
    case "write_bytes":
    case "remove_file":
      if (caller == this_object()) return 1;
  }

  set_this_object(caller);
  if (this_player() && interactive(this_player())) {
    path = ({string})this_player()->valid_write(path);
    if (!stringp(path)) {
      write("Bad file name.\n");
      return 0;
    }

    return ADD_SLASH(path);
  }

  path = ({string})"secure/player"->valid_write(path);
  if (stringp(path))
    return ADD_SLASH(path);

  return 0;
}

//===========================================================================
//  ed() Support
//
//===========================================================================

//---------------------------------------------------------------------------
string make_path_absolute (string str) {
  // Convert a relative filename to an absolute path for the editor.
  //
  // Argument:
  //   str : The relative filename (without leading slash).
  //
  // Result:
  //   The full pathname of the file to use. Any non-string result signals a
  //   bad file name.

  return valid_read(str,0,"make_path_absolute", this_player());
}

//---------------------------------------------------------------------------
int save_ed_setup (object who, int code) {
  // Save a wizard's ed settings.
  //
  // Arguments:
  //   who : The wizard using the editor.
  //   code: The encoded options to be saved.
  //
  // Result:
  //   Return 0 on failure, any other value for success.
  //
  // Save the given integer in a safe location for the wizard, either a file
  // or the wizard object itself.
  //
  // Be aware of possible security breaches: under !compat, write_file()
  // should be wrapped by temporarily setting the master's euid to the
  // wizard's euid.

  string file;

  if (!intp(code))
    return 0;
  file = "/players/" + lower_case(({string})who->query_name()) + "/.edrc";
  rm(file);

  return write_file(file, code + "");
}

//---------------------------------------------------------------------------
int retrieve_ed_setup (object who) {
  // Retrieve a wizard's ed settings.
  //
  // Arguments:
  //   who : The wizard using the editor.
  //
  // Result:
  //   The encoded options retrieved (0 if there are none).

  string file;
  int code;

  file = "/players/" + lower_case(({string})who->query_name()) + "/.edrc";
  if (file_size(file) <= 0)
    return 0;
  sscanf(read_file(file), "%d", code);

  return code;
}

//---------------------------------------------------------------------------
string get_ed_buffer_save_file_name (string file) {
  // Return a filename for saving the ed buffer.
  //
  // Arguments:
  //   this_player(): The wizard using the editor.
  //   file         : The name of the file currently in the buffer.
  //
  // Result:
  //   The name of the file to save the buffer into, or 0.
  //
  // This function is called when a wizard is destructed or goes netdead
  // while editing, so their work is not lost.

  string *file_ar;
  string path;

  path = "/players/"+this_player()->query_real_name()+"/.dead_ed_files";
  if (file_size(path) == -1)
    mkdir(path);
  file_ar=explode(file,"/");
  file=file_ar[sizeof(file_ar)-1];

  return path+"/"+file;
}

//===========================================================================
//  parse_command() support (!compat, SUPPLY_PARSE_COMMAND defined)
//
// LPMud has built-in support for parsing complex commands by requesting
// multiple kinds of ids from objects. The master provides defaults,
// especially for generic ids like "all the blue ones".
//
// Each function returns an array of strings (except parse_command_all_word),
// where each string is one id of that type.
//
// Parsing favors English grammar, so the default ids are English.
//===========================================================================

//---------------------------------------------------------------------------
string *parse_command_id_list () {
  // Return generic singular ids.

  return ({ "one", "thing" });
}


//---------------------------------------------------------------------------
string *parse_command_plural_id_list () {
  // Return generic plural ids.

  return ({ "ones", "things", "them" });
}


//---------------------------------------------------------------------------
string *parse_command_adjectiv_id_list () {
  // Return generic adjective ids.
  // If none are defined, return a value that is unlikely to be used.

  return ({ "iffish" });
}


//---------------------------------------------------------------------------
string *parse_command_prepos_list () {
  // Return common prepositions used by the parser.

  return ({ "in", "on", "under", "behind", "beside" });
}


//---------------------------------------------------------------------------
string parse_command_all_word() {
  // Return the single "all" word used by the parser.

  return "all";
}

//===========================================================================
// 2.4.5-Lib related functions
//===========================================================================

//---------------------------------------------------------------------------
static void wiz_decay() {
  /* Decay the "worth" entry in the wizlist. */

  mixed *wl;
  int i;

  wl = wizlist_info();
  for (i=sizeof(wl); i--; ) {
    set_extra_wizinfo(wl[i][WL_NAME], wl[i][WL_EXTRA] * 99 / 100);
  }

  call_out("wiz_decay", 3600);
}

//---------------------------------------------------------------------------
void save_wiz_file() {
  /* Save the wizlist file. */

#ifdef __WIZLIST__
  rm(__WIZLIST__);
  write_file(
    __WIZLIST__,
    implode(
      map(
        wizlist_info(),
        lambda(({'a}),
          ({#'sprintf, "%s %d %d\n",
            ({#'[, 'a, WL_NAME}),
            ({#'[, 'a, WL_COMMANDS}),
            ({#'[, 'a, WL_EXTRA})
          })
        )
      ),
      ""
    )
  );
#endif
}

//---------------------------------------------------------------------------
int verify_create_wizard (object ob) {

  /* Verify that the castle dropper is authorized to create a wizard. */

  int dummy;

  if (sscanf(object_name(ob), "domain/lp-245/room/port_castle#%d", dummy) == 1
    || sscanf(object_name(ob), "global/port_castle#%d", dummy) == 1)
    return 1;

  return 0;
}

//---------------------------------------------------------------------------
string master_create_wizard(string owner, string domain, object caller) {

  /* Create a home directory and castle for a new wizard.
  *
  * This is called automatically from create_wizard(), and the 'domain'
  * argument is ignored. The create_wizard() efun could call this directly.
  *
  * This function creates directories and files under /players, so it
  * guards against unauthorized callers.
  */

  string def_castle;
  string dest, castle, wizard;
  object player;

  /* find_player() is a simul_efun, so resolve it at runtime. */
  player = funcall(symbol_function('find_player), owner);
  if (!player)
    return 0;
  if (!verify_create_wizard(caller)) {
    tell_object(player, "That is an illegal attempt!\n");
    return 0;
  }

  if (caller != previous_object()) {
    tell_object(player, "Faked call!\n");
    return 0;
  }

  wizard = "/players/" + owner;
  castle = "/players/" + owner + "/castle.c";
  if (file_size(wizard) == -1) {
    tell_object(player, "You now have a home directory: " +
      wizard + "\n");
    mkdir(wizard);
  }

  dest = object_name(environment(player));
  def_castle = "#define NAME \"" + owner + "\"\n#define DEST \"" +
    dest + "\"\n" + read_file("/domain/lp-245/room/def_castle.c");
  if (file_size(castle) > 0) {
    tell_object(player, "You already had a castle !\n");
  } else {
    /* The master object is authorized to do this. */
    if (write_file(castle, def_castle)) {
      tell_object(player, "You now have a castle: " + castle + "\n");
      if (!write_file("/room/init_file", castle[1..] + "\n"))
        tell_object(player, "It couldn't be loaded automatically!\n");
    } else {
      tell_object(player, "Failed to make castle for you!\n");
    }

  }

  return castle;
}

/****************************************************************************/
