void start_session() {
  write("> ");

  input_to("handle_input");
}

void handle_input(string str) {
  string line, verb, arg, command_path;
  string *parts;
  object command_object;
  int handled;

  line = str;

  if (!line)
    line = "";

  line = trim(line);

  if (line == "") {
    write("> ");

    input_to("handle_input");

    return;
  }

  parts = explode(line, " ");
  verb = parts[0];

  if (sizeof(parts) > 1)
    arg = implode(parts[1..], " ");
  else
    arg = "";

  command_path = "/command/" + verb;

  if (file_size(command_path + ".c") < 0) {
    write("Unknown command.\n");
    write("> ");

    input_to("handle_input");

    return;
  }

  command_object = load_object(command_path);

  if (!objectp(command_object)) {
    write("Unknown command.\n");
    write("> ");

    input_to("handle_input");

    return;
  }

  handled = call_other(command_object, "main", arg);

  if (!handled)
    write("Unknown command.\n");

  write("> ");

  input_to("handle_input");
}
