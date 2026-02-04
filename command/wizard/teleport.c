inherit "/core/command";

void create() {
  ::create();

  set_category("Wizard");
  set_help_text(
    "Usage: teleport <path>\n"
    "Move directly to the room at the given file path.\n"
  );
}

int main(string arg) {
  object player;
  object room;
  string target, path, filename;
  string *parts;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    write("Usage: teleport <path>\n");

    return 1;
  }

  path = target;

  if (path[<2..] != ".c" && file_size(path) < 0 && file_size(path + ".c") >= 0)
    path = path + ".c";

  if (file_size(path) < 0) {
    write("No such room: " + path + "\n");

    return 1;
  }

  room = load_object(path);

  if (!objectp(room)) {
    write("Unable to load room: " + path + "\n");

    return 1;
  }

  player->move(room);

  parts = explode(path, "/");
  filename = parts[sizeof(parts) - 1];

  write("You have teleported to " + filename + ".\n");

  if (function_exists("show_location", player))
    player->show_location(1, 1);

  return 1;
}
