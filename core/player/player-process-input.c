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

  command_path = "/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    if (command->main(arg))
      return "";
    else
      return raw;
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

  player = this_object();
  env = environment(player);

  if (objectp(env)) {
    endpoint_id = base_name(env);
    links = LINK_D->links_for_room(endpoint_id);
    matches = ({ });

    if (pointerp(links) && sizeof(links)) {
      if (stringp(arg) && arg != "") {
        direction = "";
        remainder = "";

        if (sscanf(arg, "%s %s", direction, remainder) != 2) {
          direction = arg;
          remainder = "";
        }

        direction = lower_case(direction);
        dir_links = LINK_D->links_by_direction_for_room(endpoint_id);

        if (mapp(dir_links) && objectp(dir_links[direction])) {
          links = ({ dir_links[direction] });
          arg = remainder;
        }
      }

      for (i = 0; i < sizeof(links); i++) {
        link = links[i];

        if (!objectp(link))
          continue;

        if (function_exists("query_action_match", link)) {
          match = link->query_action_match(player, verb, arg, endpoint_id);

          if (mapp(match) && match["matched"])
            matches += ({ ([ "link" : link, "match" : match ]) });
        }
      }
    }

    if (pointerp(matches) && sizeof(matches) == 1) {
      entry = matches[0];
      link = entry["link"];

      if (objectp(link) && function_exists("handle_action", link)) {
        handled = link->handle_action(player, verb, arg, endpoint_id);

        if (handled)
          return "";
      }
    }

    if (pointerp(matches) && sizeof(matches) > 1) {
      example_dir = "";
      gate_name = "";

      entry = matches[0];
      match = entry["match"];

      if (mapp(match) && stringp(match["name"]))
        gate_name = match["name"];

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

  return raw;
}
