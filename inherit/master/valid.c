#include <globals.h>

int inherit_called = 0;

int get_inherit_called() {
  return inherit_called;
}

void create() {
  write("apply create called in valid.c\n");
}

int valid_shadow(object ob) {
  write("apply valid_shadow called in valid.c\n");
  write("-- ob: " + ob + "\n");

#ifdef __PACKAGE_UIDS__
  if (getuid(ob) == ROOT_UID)
    return 1; /* for test */
#endif
  if (ob->query_prevent_shadow(previous_object()))
    return 0;

  return 1;
}

int valid_author(string str) {
  write("apply valid_author called in valid.c\n");
  write("-- str: " + str + "\n");

  return 1;
}

// valid_override: controls which simul_efuns may be overridden with
// efun:: prefix and which may not.  This function is only called at
// object compile-time.
//
// returns: 1 if override is allowed, 0 if not.
int valid_override(string file, string efun_name, string main_file) {
  write("apply valid_override called in valid.c\n");
  write("-- file: " + file + "\n");
  write("-- efun_name: " + efun_name + "\n");
  write("-- main_file: " + main_file + "\n");

  if (file == MFUN_OB)
    return 1;

  if ((efun_name == "move_object") && (file != BASE_OB))
    return 0;

  //  may also wish to protect destruct, shutdown, snoop, and exec.
  return 1;
}

// valid_seteuid: determines whether an object ob can become euid str.
// returns: 1 if seteuid() may succeed, 0 if not.
int valid_seteuid(object obj, string euid) {
  write("apply valid_seteuid called in valid.c\n");
  write("-- obj: " + obj + "\n");
  write("-- euid: " + euid + "\n");

  return 1;
}

// valid_domain: decides if a domain may be created
// returns: 1 if domain may be created, 0 if not.
int valid_domain(string str) {
  write("apply valid_domain called in valid.c\n");
  write("-- str: " + str + "\n");

  return 1;
}

// valid_socket: controls access to socket efunctions
// return: 1 if access allowed, 0 if not.
int valid_socket(object caller, string func, mixed *info) {
  write("apply valid_socket called in valid.c\n");
  write("-- caller: " + caller + "\n");
  write("-- func: " + func + "\n");
  write("-- info: <mixed *>\n");

  return 1;
}

// Write and Read privileges:

// valid_write: called with the file name, the object initiating the call,
//  and the function by which they called it.
// return: 1 if access allowed, 0 if access not allowed.
int valid_write(string file, mixed user, string func) {
  write("apply valid_write called in valid.c\n");
  write("-- file: " + file + "\n");
  write("-- user: " + user + "\n");
  write("-- func: " + func + "\n");

  inherit_called++;

  return 1;
}


// valid_read:  called exactly the same as valid_write()
int valid_read(string file, mixed user, string func) {
  write("apply valid_read called in valid.c\n");
  write("-- file: " + file + "\n");
  write("-- user: " + user + "\n");
  write("-- func: " + func + "\n");

  inherit_called++;

  return 1;
}

int valid_bind(object binder, object old_owner, object new_owner) {
  write("apply valid_bind called in valid.c\n");
  write("-- binder: " + binder + "\n");
  write("-- old_owner: " + old_owner + "\n");
  write("-- new_owner: " + new_owner + "\n");

  inherit_called++;

  // This is really unsafe, but testsuite uses it to test bind()
  return 1;
}

int valid_hide(object ob) {
  write("apply valid_hide called in valid.c\n");
  write("-- ob: " + ob + "\n");

  inherit_called++;

  // same here
  return 1;
}
