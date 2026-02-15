inherit "/core/login/phases/base_phase";

void begin_phase() {
  write_line("Choose a password (6-20 chars, upper/lower, number, special).");
  prompt_secret("Password:");

  return;
}

void handle_input(string input) {
  string password;

  if (!stringp(input))
    input = "";

  password = cleaned(input);

  if (!is_valid_password(password)) {
    if (register_password_failure())
      return;

    write_line("That password does not meet the requirements.");
    begin_phase();
    return;
  }

  clear_password_failures();
  query_session()->set_session_value("temp_password", password);
  query_session()->advance_phase("/core/login/phases/confirm_password");

  return;
}
