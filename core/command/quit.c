inherit "/core/command/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: quit\n"
    "Leave the game and end your current session.\n"
    "Your character disappears from the world.\n"
  );
}

int main(string arg) {
  write("Bye.\n");

  say(
    (string)previous_object()->name()
    + " leaves this reality.\n"
  );

  previous_object()->remove();

  return 1;
}
