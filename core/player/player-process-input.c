/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command;
  object player, env, link;
  object *links, *matches;
  mapping dir_links;
  mapping match;
  mapping entry;
  string verb, arg, command_path, endpoint_id;
  string direction;
  string remainder;
  string example_dir;
  string gate_name;
  int i;
  int handled;

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
    // Resolve the current room and gather its links.
    endpoint_id = base_name(env);
    links = LINK_D->links_for_room(endpoint_id);
    matches = ({ });

    if (pointerp(links) && sizeof(links)) {
      // If the command has an argument, try to treat it as a direction.
      if (stringp(arg) && arg != "") {
        direction = "";
        remainder = "";

        if (sscanf(arg, "%s %s", direction, remainder) != 2) {
          direction = arg;
          remainder = "";
        }

        // Normalize the direction token for lookup.
        direction = lower_case(direction);
        dir_links = LINK_D->links_by_direction_for_room(endpoint_id);

        // When a direction is valid, narrow to that link and keep remainder.
        if (mapp(dir_links) && objectp(dir_links[direction])) {
          links = ({ dir_links[direction] });
          arg = remainder;
        }
      }

      // Ask each link if it wants to claim this verb+arg.
      for (i = 0; i < sizeof(links); i++) {
        link = links[i];

        if (!objectp(link))
          continue;

        if (function_exists("query_action_match", link)) {
          match = link->query_action_match(player, verb, arg, endpoint_id);

          // Store both the link and its match metadata for later resolution.
          if (mapp(match) && match["matched"])
            matches += ({ ([ "link" : link, "match" : match ]) });
        }
      }
    }

    // A single match is authoritative; hand off to the link.
    if (pointerp(matches) && sizeof(matches) == 1) {
      entry = matches[0];
      link = entry["link"];

      if (objectp(link) && function_exists("handle_action", link)) {
        handled = link->handle_action(player, verb, arg, endpoint_id);

        // Successful handling ends input processing.
        if (handled)
          return "";
      }
    }

    // Multiple matches need disambiguation by direction.
    if (pointerp(matches) && sizeof(matches) > 1) {
      example_dir = "";
      gate_name = "";

      // Use the first match's name to hint what the player meant.
      entry = matches[0];
      match = entry["match"];

      if (mapp(match) && stringp(match["name"]))
        gate_name = match["name"];

      // Find a direction label to include in the prompt example.
      for (i = 0; i < sizeof(matches); i++) {
        entry = matches[i];
        link = entry["link"];

        if (!objectp(link))
          continue;

        if (function_exists("query_direction_label", link))
          example_dir = link->query_direction_label(endpoint_id);

        if (stringp(example_dir) && example_dir != "")
          break;
      }

      // Tell the player how to disambiguate the target.
      if (stringp(example_dir) && example_dir != "") {
        if (stringp(gate_name) && gate_name != "")
          write(
            "Please specify a direction; for example, '" +
            example_dir + " " + gate_name + "'.\n"
          );
        else
          write(
            "Please specify a direction; for example, '" +
            example_dir + "'.\n"
          );
      } else {
        write("Please specify a direction.\n");
      }

      return "";
    }
  }

  // Let unmatched input fall through to default driver handling.
  return raw;
}
