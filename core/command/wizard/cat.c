/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/wizard/cat.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 *   - #include <globals.h>
 */

inherit "/core/command/command";
#include <globals.h>

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
    "Usage: cat <target> or cat here\n"
    "Display source for an in-room object, the current room, or a file path.\n"
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
  object env;
  object target_object;
  string target, normalized_target, path, contents;
  string candidate_path;
  int show_object_header;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);
  show_object_header = 0;

  if (target == "") {
    avatar_experience(avatar, "Usage: cat <target> or cat here\n");

    return 1;
  }

  env = environment(avatar);
  normalized_target = lower_case(target);

  if (normalized_target == "here") {
    if (!objectp(env)) {
      avatar_experience(avatar, "You are nowhere.\n");

      return 1;
    }

    path = base_name(env) + ".c";
    show_object_header = 1;
  } else {
    path = "";
    target_object = resolve_environment_target(avatar, normalized_target);

    if (objectp(target_object)) {
      candidate_path = base_name(target_object);

      if (stringp(candidate_path) && candidate_path != "") {
        path = candidate_path + ".c";
        show_object_header = 1;
      }
    }

    if (path == "")
      path = target;
  }

  if (sizeof(path) < 2)
    path = path + ".c";
  else if (path[<2..] != ".c" && file_size(path) < 0 &&
    file_size(path + ".c") >= 0)
    path = path + ".c";

  if (file_size(path) < 0) {
    avatar_experience(avatar, "No such file: " + path + "\n");

    return 1;
  }

  contents = read_file(path);

  if (!stringp(contents)) {
    avatar_experience(avatar, "Unable to read file.\n");

    return 1;
  }

  if (show_object_header) {
    avatar_experience(avatar, path + "\n");
    avatar_experience(avatar, DISPLAY_DIVIDER + "\n");
  }

  avatar_experience(avatar, contents);

  if (contents == "" || contents[<1] != '\n')
    avatar_experience(avatar, "\n");

  return 1;
}
