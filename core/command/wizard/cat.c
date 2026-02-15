/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/wizard/cat.c.
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

  set_category("Wizard");
  set_help_text(
    "Usage: cat <path> or cat here\n"
    "Display the contents of a file. Use 'here' to read the current room.\n"
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
  object player;
  object env;
  string target, path, contents;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    write("Usage: cat <path> or cat here\n");

    return 1;
  }

  if (lower_case(target) == "here") {
    env = environment(player);

    if (!objectp(env)) {
      write("You are nowhere.\n");

      return 1;
    }

    path = base_name(env) + ".c";
  } else {
    path = target;
  }

  if (path[<2..] != ".c" && file_size(path) < 0 && file_size(path + ".c") >= 0)
    path = path + ".c";

  if (file_size(path) < 0) {
    write("No such file: " + path + "\n");

    return 1;
  }

  contents = read_file(path);

  if (!stringp(contents)) {
    write("Unable to read file.\n");

    return 1;
  }

  write(contents);

  if (contents == "" || contents[<1] != '\n')
    write("\n");

  return 1;
}
