/*
 * /core/command/go.c
 *
 * Minimal movement command using Link-based traversal.
 *
 * This command:
 * - resolves a direction label in the current room
 * - retrieves the corresponding Link
 * - delegates all movement logic to the Link
 *
 * No exits. No doors. No room logic.
 */
inherit "/core/command";

#include <link.h>

mapping direction_aliases;
string *direction_words;
string implied_prefix;

void create() {
  ::create();

  direction_words = ({
    "north",
    "south",
    "east",
    "west",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "in",
    "out",
    "enter",
    "exit"
  });

  direction_aliases = ([
    "n" : "north",
    "s" : "south",
    "e" : "east",
    "w" : "west",
    "ne" : "northeast",
    "nw" : "northwest",
    "se" : "southeast",
    "sw" : "southwest",
    "u" : "up",
    "d" : "down"
  ]);

  implied_prefix = "__implied__:";

  set_category("Movement");
  set_help_text(
    "Usage: go <direction>\n"
    "Move through a registered link in the given direction.\n"
  );
}

int main(string arg) {
  object player, env, link;
  mapping result;
  string msg, normalized, implied_arg;
  int implied;

  player = this_player();

  if (!objectp(player))
    return 0;

  env = environment(player);

  if (!objectp(env))
    return 0;

  implied = 0;
  implied_arg = "";

  if (stringp(arg) && sscanf(arg, implied_prefix + "%s", implied_arg) == 1) {
    implied = 1;
    arg = implied_arg;
  }

  if (!stringp(arg))
    arg = "";

  arg = lower_case(trim(arg));

  if (arg == "") {
    write("Go where?\n");

    return 1;
  }

  normalized = arg;

  if (mapp(direction_aliases) && stringp(direction_aliases[normalized]))
    normalized = direction_aliases[normalized];

  if (implied && member_array(normalized, direction_words) == -1)
    return 0;

  /*
   * Ask the room for the Link corresponding to this label.
   * Room is responsible only for affordance mapping.
   */
  if (!function_exists("query_link", env)) {
    write("You can't go that way.\n");

    return 1;
  }

  link = env->query_link(normalized);

  if (!objectp(link)) {
    write("You can't go that way.\n");

    return 1;
  }

  /*
   * Delegate movement to the Link.
   */
  result = link->traverse(player, env);

  if (!mapp(result)) {
    write("Something goes wrong.\n");

    return 1;
  }

  /*
   * Handle link-owned narration.
   * Room/actor narration already happened inside traversal hooks.
   */
  msg = result[LINK_RESULT_MESSAGE];

  if (stringp(msg) && msg != "")
    write(msg + "\n");

  return 1;
}
