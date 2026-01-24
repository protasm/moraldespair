void start_session() {
  write("> ");
  input_to("handle_input");
}

void handle_input(string str) {
  string line;

  line = str;

  if (!line) {
    line = "";
  }

  write("You typed: '" + line + "'\n");
  write("> ");
  input_to("handle_input");
}
