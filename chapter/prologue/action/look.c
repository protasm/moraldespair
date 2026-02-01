inherit "/core/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: look or look <target>\n"
    "Show the description of your current location.\n"
    "You can also look at a specific target to inspect it.\n"
  );
}

int main(string arg) {
  object player;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (function_exists("show_location", player)) {
    player->show_location();

    return 1;
  }

  write("You are nowhere.\n");

  return 1;
}
