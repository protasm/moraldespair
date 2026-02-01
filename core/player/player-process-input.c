/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command;
  object player, env;
  object link_cache;
  string verb, arg, command_path;

  // Ignore non-string input so command parsing does not explode.
  if (!stringp(raw))
    return "";

  // Normalize whitespace before any parsing.
  raw = trim(raw);

  // Drop empty input lines early.
  if (raw == "")
    return "";

  // Split verb from argument, defaulting to empty arg.
  if (sscanf(raw, "%s %s", verb, arg) != 2) {
    verb = raw;
    arg = "";
  }

  // Commands are case-insensitive, keep the verb normalized.
  verb = lower_case(verb);

  // Look for core command implementations first.
  command_path = "/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // If the command handles the input, swallow the line.
    if (command->main(arg))
      return "";
    else
      return raw;
  }

  // Fall back to chapter-specific actions if core commands miss.
  command_path = "/chapter/prologue/action/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // Let chapter actions decide whether the input is consumed.
    if (command->main(arg))
      return "";
    else
      return raw;
  }

  // Try the "go" action as a last-resort movement handler.
  command_path = "/chapter/prologue/action/go";

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // Pass the verb as the direction when "go" is the fallback.
    if (command->main(verb))
      return "";
  }

  // Begin room-specific action matching.
  player = this_object();
  env = environment(player);

  if (objectp(env)) {
    if (function_exists("query_link_cache", env))
      link_cache = env->query_link_cache();

    if (objectp(link_cache) && function_exists("handle_input", link_cache)) {
      if (link_cache->handle_input(player, verb, arg))
        return "";
    }
  }

  // Let unmatched input fall through to default driver handling.
  return raw;
}
