/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command;
  string verb, arg, command_path;

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

write("DEBUG: trying command '" + verb + "'\n");
  command_path = "/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    command->main(arg);

    return "";
  }

write("DEBUG: trying action '" + verb + "'\n");
  command_path = "/chapter/prologue/action/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    command->main(arg);

    return "";
  }

write("DEBUG: trying implied go '" + verb + "'\n");
  command_path = "/chapter/prologue/action/go";

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    if (command->main(verb))
      return "";
  }

write("DEBUG: falling through\n");
  return raw;
}
