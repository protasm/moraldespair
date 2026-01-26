inherit "/core/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "List connected players and their idle time.\n"
    "Indicators show who is editing or entering input.\n"
  );
}

int main(string arg) {
  object *list;
  int j;
  string name;

  printf("%-25s idle\n", "name (*edit, +input)");
  printf("--------------------      ----\n");

  list = users();

  for (j = 0; j < sizeof(list); j++) {
    name = (string)list[j]->query_name();

    if (in_edit(this_player()))
      name += "*";

    if (in_input(this_player()))
      name += "+";

    printf(
      "%-25s %4d\n",
      name,
      query_idle(this_player()) / 60
    );
  }

  return 1;
}
