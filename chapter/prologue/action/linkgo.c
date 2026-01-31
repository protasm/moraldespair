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
  string *valid_directions;
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

  valid_directions = ({
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
    "exit",
    "city"
  });

  location = environment(player);

  if (!objectp(location))
    return 0;

  if (!function_exists("link_for", location))
    return 0;

  direction = directions[arg];

  if (!stringp(direction))
    direction = arg;

  link = location->link_for(direction);

  if (!objectp(link)) {
    if (member_array(direction, valid_directions) == -1)
      return 0;

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
