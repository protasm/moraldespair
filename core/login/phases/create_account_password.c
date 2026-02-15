inherit "/core/login/phases/base_phase";

void begin_phase() {
  write_line("Choose a password (6-20 chars, upper/lower, number, special).");
  prompt_secret("Password:");

  return;
}

void handle_input(string input) {
  if (!stringp(input))
    input = "";

  if (!is_valid_password(input)) {
    write_line("That password does not meet the requirements.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("temp_password", input);
  query_session()->advance_phase("/core/login/phases/confirm_password");

  return;
}
