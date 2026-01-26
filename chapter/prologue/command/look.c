#include <command.h>

int main(string arg) {
  object player, location;
  string description;

  player = this_player();

  if (!objectp(player))
    return 0;

  location = environment(player);

  if (!objectp(location)) {
    write("There is nothing here.\n");

    return 1;
  }

  description = location->long(arg);

  if (!stringp(description))
    return 0;

  if (strlen(description) && description[<1] != '\n')
    description += "\n";

  write(description);

  return 1;
}
