#include <command.h>

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Show the description of your current location.\n"
    "You can also look at a specific target to inspect it.\n"
  );
}

int main(string arg) {
  object player, location;
  string description, short_desc, divider;

  player = this_player();

  if (!objectp(player))
    return 0;

  location = environment(player);

  if (!objectp(location)) {
    write("There is nothing here.\n");

    return 1;
  }

  short_desc = location->short();
  description = location->long(arg);

  if (!stringp(description))
    return 0;

  if (!stringp(short_desc))
    short_desc = "";

  divider = "---------+---------+---------+---------+---------+---------+---------+---------+";

  if (short_desc == "" || short_desc[<1] != '\n')
    short_desc += "\n";

  if (divider[<1] != '\n')
    divider += "\n";

  description = short_desc + divider + description;

  if (strlen(description) && description[<1] != '\n')
    description += "\n";

  write(description);

  return 1;
}
