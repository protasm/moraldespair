inherit "/core/command/command";

void create() {
  ::create();

  set_category("Communication");
  set_help_text(
    "Usage: say <message>\n"
    "Speak to everyone in your current location.\n"
    "Your words are heard by anyone nearby.\n"
  );
}

int main(string arg) {
  object player;
  string spoken_text;
  string player_name;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    arg = "";

  spoken_text = trim(arg);

  if (spoken_text == "") {
    write("Say what?\n");
    return 1;
  }

  player_name = player->name();

  if (!stringp(player_name) || player_name == "")
    player_name = "Someone";

  write("You say, '" + spoken_text + "'\n");

  say(
    player_name + " says, '" + spoken_text + "'\n",
    player
  );

  return 1;
}
