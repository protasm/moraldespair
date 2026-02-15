/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/confirm_password.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/login/phases/base_phase";
 *   - #include <globals.h>
 */

inherit "/core/login/phases/base_phase";

#include <globals.h>

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
  prompt_secret("Confirm password:");

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
  string account_name;
  string password;
  string password_hash;
  string display;
  int created;

  if (!stringp(input))
    input = "";

  if (require_nonempty_input(input))
    return;

  account_name = normalized(query_session()->query_session_value("account_name"));
  password = query_session()->query_session_value("temp_password");

  if (account_name == "" || !stringp(password) || password == "") {
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  if (input != password) {
    write_line("Passwords did not match. Please choose again.");
    query_session()->remove_session_value("temp_password");
    query_session()->advance_phase("/core/login/phases/create_account_password");
    return;
  }

  password_hash = crypt(password, make_salt());
  display = capitalize(account_name);
  created = ACCOUNT_D->create_account(account_name, display, "", password_hash);

  if (!created) {
    write_line("Unable to create account right now.");
    query_session()->remove_session_value("temp_password");
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  query_session()->set_session_value("authenticated", 1);
  query_session()->remove_session_value("temp_password");

  ACCOUNT_D->record_login(account_name);
  query_session()->push_phase("/core/login/phases/character_creation");

  return;
}
