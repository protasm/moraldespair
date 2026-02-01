/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command;
  object player, env, link;
  object *links, *matches;
  string verb, arg, command_path, endpoint_id;
  int i;

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
      for (i = 0; i < sizeof(links); i++) {
        link = links[i];

        if (!objectp(link))
          continue;

        if (function_exists("supports_action", link) &&
          link->supports_action(verb, player, endpoint_id))
          matches += ({ link });
      }
    }

    if (pointerp(matches) && sizeof(matches) == 1) {
      link = matches[0];
      link->perform_action(player, verb, arg, endpoint_id);

      return "";
    }

    if (pointerp(matches) && sizeof(matches) > 1) {
      write("That action is ambiguous.\n");

      return "";
    }
  }

  return raw;
}
