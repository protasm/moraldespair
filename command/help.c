inherit "/core/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: help or help <command>\n"
    "List available commands, grouped by category.\n"
  );
}

int main(string arg) {
  string target, path, help_text, output;
  string *files, *category_names, *commands, *prefixes;
  mapping categories;
  object command_object;
  string command, category;
  int i, j, found;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    categories = ([]);
    prefixes = ({ COMMAND_PREFIX, ACTION_PREFIX });

    for (i = 0; i < sizeof(prefixes); i++) {
      files = get_dir(prefixes[i] + "*.c");

      if (!arrayp(files) || !sizeof(files))
        continue;

      for (j = 0; j < sizeof(files); j++) {
        command = files[j];

        if (command[<2..] == ".c")
          command = command[0..<3];

        command_object = load_object(prefixes[i] + command);

        if (!objectp(command_object))
          continue;

        category = command_object->query_category();

        if (!stringp(category) || category == "")
          category = "General";

        if (!arrayp(categories[category]))
          categories[category] = ({ });

        if (member_array(command, categories[category]) == -1)
          categories[category] += ({ command });
      }
    }

    if (!sizeof(keys(categories))) {
      write("No commands are available.\n");

      return 1;
    }

    category_names = keys(categories);
    category_names = sort_array(category_names, 1);
    output = "";

    for (i = 0; i < sizeof(category_names); i++) {
      category = category_names[i];
      commands = categories[category];

      output += category + ":\n";

      commands = sort_array(commands, 1);

      output += "  " + implode(commands, ", ") + "\n";

      output += "\n";
    }

    output += "Type \"help <command>\" for more info.\n";
    write(output);

    return 1;
  }

  prefixes = ({ COMMAND_PREFIX, ACTION_PREFIX });
  found = 0;

  for (i = 0; i < sizeof(prefixes); i++) {
    path = prefixes[i] + target;

    if (file_size(path + ".c") < 0)
      continue;

    command_object = load_object(path);

    if (!objectp(command_object))
      continue;

    found = 1;

    break;
  }

  if (!found) {
    write("No help is available for that command.\n");

    return 1;
  }

  help_text = command_object->query_help_text();

  if (!stringp(help_text) || help_text == "")
    help_text = "No help text is available for this command.\n";

  if (help_text[<1] != '\n')
    help_text += "\n";

  write(help_text);

  return 1;
}
