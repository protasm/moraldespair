/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command;
  string input, verb, arg, command_path, implied_input;

  if (!stringp(raw))
    return "";

  input = trim(raw);

  if (input == "")
    return "";

  if (sscanf(input, "%s %s", verb, arg) != 2) {
    verb = input;
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

write("DEBUG: trying implied go '" + input + "'\n");
  command_path = "/chapter/prologue/action/go";

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    implied_input = "__implied__:" + input;

    if (command->main(implied_input))
      return "";
  }

write("DEBUG: falling through\n");
  return raw;
}
