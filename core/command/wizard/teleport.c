/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/wizard/teleport.c.
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
    "Usage: teleport <path>\n"
    "Move directly to the room at the given file path.\n"
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
  object avatar;
  object room;
  string target, path, filename;
  string *parts;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    avatar_experience(avatar, "Usage: teleport <path>\n");

    return 1;
  }

  path = target;

  if (path[<2..] != ".c" && file_size(path) < 0 && file_size(path + ".c") >= 0)
    path = path + ".c";

  if (file_size(path) < 0) {
    avatar_experience(avatar, "No such room: " + path + "\n");

    return 1;
  }

  room = load_object(path);

  if (!objectp(room)) {
    avatar_experience(avatar, "Unable to load room: " + path + "\n");

    return 1;
  }

  avatar->move(room);

  parts = explode(path, "/");
  filename = parts[sizeof(parts) - 1];

  avatar_experience(avatar, "You have teleported to " + filename + ".\n");

  if (function_exists("show_location", avatar))
    avatar->show_location(1, 1);

  return 1;
}
