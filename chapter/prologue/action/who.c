inherit "/core/command/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: who\n"
    "List connected avatars and their idle time.\n"
    "Indicators show who is editing or entering input.\n"
  );
}

int main(string arg) {
  object avatar_self;
  object *list;
  object avatar;
  object player;
  int j;
  int idle_minutes;
  string name;
  string status;
  string line;
  string output;

  avatar_self = current_avatar();

  if (!is_avatar(avatar_self))
    return 0;

  output = sprintf("%-25s status\n", "name (*edit, +input)");
  output += "--------------------      ----------\n";

  list = connected_avatars();

  for (j = 0; j < sizeof(list); j++) {
    avatar = list[j];
    name = "";
    status = "";

    if (!objectp(avatar))
      continue;

    if (function_exists("short_for", avatar))
      name = avatar->short_for(avatar_self);

    if (!stringp(name) || name == "")
      if (function_exists("short", avatar))
        name = avatar->short();

    if (!stringp(name) || name == "")
      if (function_exists("name", avatar))
        name = avatar->name();

    if (!stringp(name) || name == "")
      name = "(unknown)";

    player = avatar_controller(avatar);

    if (!objectp(player))
      continue;

    if (in_edit(player))
      name += "*";

    if (in_input(player))
      name += "+";

    if (function_exists("query_session_data", player))
      status = "Logging In";
    else {
      idle_minutes = query_idle(player) / 60;
      status = "" + idle_minutes;
    }

    line = sprintf(
      "%-25s %s\n",
      name,
      status
    );
    output += line;
  }

  avatar_experience(avatar_self, output);

  return 1;
}
