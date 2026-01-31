inherit "/core/command";

#include <link.h>

void create() {
  ::create();

  set_category("Movement");
  set_help_text(
    "Usage: linkgo <direction>\n"
    "Move through a registered link in the given direction.\n"
  );
}

int main(string arg) {
  object player, location, link;
  mapping directions;
  mapping result;
  string direction, message;
  int outcome;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    return 0;

  arg = trim(arg);

  if (arg == "")
    return 0;

  arg = lower_case(arg);

  directions = ([
    "north" : "north",
    "south" : "south",
    "east" : "east",
    "west" : "west",
    "northeast" : "northeast",
    "northwest" : "northwest",
    "southeast" : "southeast",
    "southwest" : "southwest",
    "up" : "up",
    "down" : "down",
    "n" : "north",
    "s" : "south",
    "e" : "east",
    "w" : "west",
    "ne" : "northeast",
    "nw" : "northwest",
    "se" : "southeast",
    "sw" : "southwest",
    "u" : "up",
    "d" : "down",
    "x" : "exit",
    "c" : "city"
  ]);

  direction = directions[arg];

  if (!stringp(direction))
    direction = arg;

  location = environment(player);

  if (!objectp(location))
    return 0;

  if (!function_exists("link_for", location))
    return 0;

  link = location->link_for(direction);

  if (!objectp(link)) {
    write("You can't go that way.\n");

    return 1;
  }

  result = link->traverse(player, location);
  message = result[LINK_RESULT_MESSAGE];

  if (stringp(message) && message != "")
    write(message + "\n");

  outcome = result[LINK_RESULT_OUTCOME];

  if (outcome == LINK_OUTCOME_ALLOW ||
      outcome == LINK_OUTCOME_ALLOW_REVERSE ||
      outcome == LINK_OUTCOME_ALLOW_REDIRECT ||
      outcome == LINK_OUTCOME_ALLOW_MUTATE) {
    if (function_exists("show_location", player))
      player->show_location();
  }

  return 1;
}
