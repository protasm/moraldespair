/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/wizard/reload.c.
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
    "Usage: reload <target> or reload here\n"
    "Reload an object by path, in-room object name, or current room.\n"
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
  object existing_object;
  object reloaded_object;
  mixed load_error;
  string target;
  string normalized_target;
  string path;
  string loaded_path;
  string *load_candidates;
  int i;
  int reloading_current_room;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = trim(arg);

  if (target == "") {
    avatar_experience(avatar, "Usage: reload <target> or reload here\n");

    return 1;
  }

  normalized_target = lower_case(target);
  env = environment(avatar);
  target_object = 0;
  path = "";

  if (normalized_target == "here") {
    if (!objectp(env)) {
      avatar_experience(avatar, "You are nowhere.\n");

      return 1;
    }

    target_object = env;
    path = base_name(env);
  } else {
    target_object = resolve_environment_target(avatar, normalized_target);

    if (objectp(target_object))
      path = base_name(target_object);
    else
      path = target;
  }

  if (!stringp(path) || trim(path) == "") {
    avatar_experience(avatar, "Unable to resolve reload target.\n");

    return 1;
  }

  path = trim(path);
  load_candidates = ({ path });

  if (sizeof(path) >= 2 && path[<2..] == ".c")
    load_candidates += ({ path[0..<3] });
  else
    load_candidates += ({ path + ".c" });

  existing_object = 0;

  for (i = 0; i < sizeof(load_candidates); i++) {
    if (!objectp(existing_object))
      existing_object = find_object(load_candidates[i]);
  }

  if (objectp(target_object))
    existing_object = target_object;

  reloading_current_room = 0;

  if (objectp(existing_object) && objectp(env) && existing_object == env)
    reloading_current_room = 1;

  if (objectp(existing_object))
    destruct(existing_object);

  reloaded_object = 0;
  loaded_path = "";

  for (i = 0; i < sizeof(load_candidates); i++) {
    load_error = catch(reloaded_object = load_object(load_candidates[i]));

    if (!load_error && objectp(reloaded_object)) {
      loaded_path = load_candidates[i];

      break;
    }
  }

  if (!objectp(reloaded_object)) {
    avatar_experience(avatar, "Unable to reload object: " + path + "\n");

    return 1;
  }

  if (reloading_current_room && function_exists("move", avatar))
    avatar->move(reloaded_object);

  avatar_experience(
    avatar,
    "Reloaded: " + base_name(reloaded_object) + " (from " + loaded_path + ")\n"
  );

  if (reloading_current_room && function_exists("show_location", avatar))
    avatar->show_location(1, 1);

  return 1;
}
