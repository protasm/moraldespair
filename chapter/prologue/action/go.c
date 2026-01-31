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

  set_category("Movement");
  set_help_text(
    "Usage: go <direction>\n"
    "Move through a registered link in the given direction.\n"
  );
}

int main(string arg) {
  object player, env, link;
  mapping result;
  string msg;

  player = this_player();

  if (!objectp(player))
    return 0;

  env = environment(player);

  if (!objectp(env))
    return 0;

  if (!stringp(arg))
    arg = "";

  arg = lower_case(trim(arg));

  if (arg == "") {
    write("Go where?\n");

    return 1;
  }

  if (mapp(direction_aliases) && stringp(direction_aliases[arg]))
    arg = direction_aliases[arg];

  /*
   * Ask the room for the Link corresponding to this label.
   * Room is responsible only for affordance mapping.
   */
  link = env->query_link(arg);

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
