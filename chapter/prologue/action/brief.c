inherit "//core/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: brief\n"
    "Toggle brief mode for room descriptions.\n"
  );
}

int main(string arg) {
  object player;
  int enabled;

  player = this_player();

  if (!objectp(player))
    return 0;

  enabled = player->toggle_brief();

  if (enabled)
    write("Brief mode enabled.\n");
  else
    write("Verbose mode enabled.\n");

  return 1;
}
