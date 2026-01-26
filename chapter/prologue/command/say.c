#include <command.h>

void create() {
  ::create();

  set_category("Communication");
  set_help_text(
    "Speak to everyone in your current location.\n"
    "Use: say <message>\n"
  );
}

int main(string arg) {
  say(
    (string)previous_object()->query_name()
    + " says: " +  arg + "\n"
  );

  return 1;
}
