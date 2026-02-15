/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/create_account_password.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/login/phases/base_phase";
 */

inherit "/core/login/phases/base_phase";

/* Method Summary:
 * Purpose:
 *   Handles begin_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for begin_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from begin_phase.
 */
void begin_phase() {
  write_line("Choose a password (6-20 chars, upper/lower, number, special).");
  prompt_secret("Password:");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles handle_input for this object.
 * Parameters:
 *   - string input
 * Approach:
 *   Validates inputs and executes explicit local logic for handle_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from handle_input.
 */
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
