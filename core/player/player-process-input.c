/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/player/player-process-input.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
/* Method Summary:
 * Purpose:
 *   Handles process_input for this object.
 * Parameters:
 *   - string raw
 * Approach:
 *   Routes player input to command handlers using the controlled avatar as
 *   the in-world actor.
 * Side effects:
 *   May trigger game actions and writes back to the interactive player.
 * Returns:
 *   string result from process_input.
 */
string process_input(string raw) {
  object combat_daemon;
  object command;
  object avatar_object;
  object env;
  object link_cache;
  string verb, arg, command_path;
  int avatar_is_wizard;

  if (!stringp(raw))
    return "";

  raw = trim(raw);

  if (raw == "")
    return "";

  if (sscanf(raw, "%s %s", verb, arg) != 2) {
    verb = raw;
    arg = "";
  }

  verb = lower_case(verb);
  avatar_object = avatar();

  if (!objectp(avatar_object)) {
    write("No avatar is active.\n");

    return "";
  }

  if (function_exists("query_in_combat", avatar_object)) {
    if (avatar_object->query_in_combat()) {
      if (verb != "auto") {
        combat_daemon = find_object(COMBAT_D);

        if (!objectp(combat_daemon))
          combat_daemon = load_object(COMBAT_D);

        if (objectp(combat_daemon) && function_exists("handle_input", combat_daemon)) {
          combat_daemon->handle_input(avatar_object, raw);

          return "";
        }
      }
    }
  }

  command_path = "/core/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    if (command->main(arg))
      return "";
    else
      return raw;
  }

  avatar_is_wizard = 0;

  if (function_exists("is_wizard", avatar_object))
    avatar_is_wizard = avatar_object->is_wizard();

  if (avatar_is_wizard || wizardp(avatar_object)) {
    command_path = "/core/command/wizard/" + verb;

    if (file_size(command_path + ".c") >= 0) {
      command = load_object(command_path);

      if (command->main(arg))
        return "";
      else
        return raw;
    }
  }

  command_path = "/chapter/prologue/action/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    if (command->main(arg))
      return "";
    else
      return raw;
  }

  command_path = "/chapter/prologue/action/go";

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    if (command->main(verb))
      return "";
  }

  env = environment(avatar_object);

  if (objectp(env)) {
    if (function_exists("link_cache", env))
      link_cache = env->link_cache();

    if (objectp(link_cache) && function_exists("handle_input", link_cache)) {
      if (link_cache->handle_input(avatar_object, verb, arg))
        return "";
    }
  }

  if (function_exists("process_input", avatar_object))
    if (avatar_object->process_input(raw) == "")
      return "";

  return raw;
}
