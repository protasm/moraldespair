inherit "/core/command";

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
  say(
    (string)previous_object()->query_name()
    + " says: " +  arg + "\n"
  );

  return 1;
}
