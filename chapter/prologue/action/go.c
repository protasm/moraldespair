/*
 * /core/command/go.c
 *
 * Minimal movement command using Link-based traversal.
 *
 * This command:
 * - normalizes the direction label
 * - delegates movement to MOVE_D
 *
 * No exits. No doors. No room logic.
 */
inherit "/core/command/command";

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
    "Attmpt to move to or through the given direction.\n"
  );
}

int main(string arg) {
  object avatar;
  int is_direction;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  arg = lower_case(trim(arg));

  if (arg == "") {
    avatar_experience(avatar, "Go where?\n");

    return 1;
  }

  if (mapp(direction_aliases) && stringp(direction_aliases[arg]))
    arg = direction_aliases[arg];

  is_direction = (member_array(arg, direction_words) != -1);

  if (is_direction) {
    MOVE_D->try_move(avatar, arg);

    return 1;
  }

  if (MOVE_D->try_move_label(avatar, arg))
    return 1;

  return 0;
}
