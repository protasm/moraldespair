inherit "/core/command";

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: help or help <command>\n"
    "List available commands, grouped by category.\n"
    "Use: help <command> to read more about a specific command.\n"
  );
}

int main(string arg) {
  string target, path, help_text, output;
  string *files, *category_names, *commands;
  mapping categories;
  object command_object;
  string command, category;
  int i;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    categories = ([]);
    files = get_dir(COMMAND_PREFIX + "*.c");

    if (!arrayp(files) || !sizeof(files)) {
      write("No commands are available.\n");

      return 1;
    }

    for (i = 0; i < sizeof(files); i++) {
      command = files[i];

      if (command[<2..] == ".c")
        command = command[0..<3];

      command_object = load_object(COMMAND_PREFIX + command);

      if (!objectp(command_object))
        continue;

      category = command_object->query_category();

      if (!stringp(category) || category == "")
        category = "General";

      if (!arrayp(categories[category]))
        categories[category] = ({ });

      categories[category] += ({ command });
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

  path = COMMAND_PREFIX + target;

  if (file_size(path + ".c") < 0) {
    write("No help is available for that command.\n");

    return 1;
  }

  command_object = load_object(path);

  if (!objectp(command_object)) {
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
