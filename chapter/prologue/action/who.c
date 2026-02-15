inherit "/core/command/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: who\n"
    "List connected players and their idle time.\n"
    "Indicators show who is editing or entering input.\n"
  );
}

int main(string arg) {
  object *list;
  object user;
  int j;
  int idle_minutes;
  string name;
  string status;

  printf("%-25s status\n", "name (*edit, +input)");
  printf("--------------------      ----------\n");

  list = users();

  for (j = 0; j < sizeof(list); j++) {
    user = list[j];
    name = "";
    status = "";

    if (!objectp(user))
      continue;

    if (function_exists("name", user))
      name = user->name();

    if (!stringp(name) || name == "")
      name = "(unknown)";

    if (in_edit(user))
      name += "*";

    if (in_input(user))
      name += "+";

    if (function_exists("query_session_data", user))
      status = "Logging In";
    else {
      idle_minutes = query_idle(user) / 60;
      status = "" + idle_minutes;
    }

    printf(
      "%-25s %s\n",
      name,
      status
    );
  }

  return 1;
}
