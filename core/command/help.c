/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/help.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 */

inherit "/core/command/command";

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: help or help <command>\n"
    "List available commands, grouped by category.\n"
  );
}

/* Method Summary:
 * Purpose:
 *   Handles main for this object.
 * Parameters:
 *   - string arg
 * Approach:
 *   Validates inputs and executes explicit local logic for main.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from main.
 */
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

    if (wizardp(this_player()))
      prefixes += ({ "/core/command/wizard/" });

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

        category = command_object->category();

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

  if (wizardp(this_player()))
    prefixes += ({ "/core/command/wizard/" });
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

  help_text = command_object->help_text();

  if (!stringp(help_text) || help_text == "")
    help_text = "No help text is available for this command.\n";

  if (help_text[<1] != '\n')
    help_text += "\n";

  write(help_text);

  return 1;
}
