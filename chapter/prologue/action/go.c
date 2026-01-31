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

void create() {
  ::create();

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

  if (!objectp(player)) {
write("In go - no player\n");
    return 0;
  }

  env = environment(player);

  if (!objectp(env)) {
write("In go - no env\n");
    return 0;
  }

  arg = trim(arg);

write("arg is '" + arg + "'\n");
  if (!stringp(arg) || arg == "") {
    write("Go where?\n");

    return 1;
  }

  /*
   * Ask the room for the Link corresponding to this label.
   * Room is responsible only for affordance mapping.
   */
  if (!function_exists("query_link", env)) {
    write("You cannot go anywhere from here.\n");

    return 1;
  }

  link = env->query_link(arg);

  if (!objectp(link))
    return 0;

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

