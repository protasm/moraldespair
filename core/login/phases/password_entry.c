/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/password_entry.c.
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
  string account_name;
  string password;
  string password_hash;
  string attempt_hash;

  if (!stringp(input))
    input = "";

  account_name = normalized(query_session()->query_session_value("account_name"));

  if (account_name == "") {
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  password = cleaned(input);

  password_hash = ACCOUNT_D->password_hash(account_name);

  if (password == "" || !stringp(password_hash) || password_hash == "") {
    if (register_password_failure())
      return;

    write_line("Password incorrect.");
    begin_phase();
    return;
  }

  attempt_hash = crypt(password, password_hash);

  if (attempt_hash != password_hash) {
    if (register_password_failure())
      return;

    write_line("Password incorrect.");
    begin_phase();
    return;
  }

  clear_password_failures();
  query_session()->set_session_value("authenticated", 1);
  ACCOUNT_D->record_login(account_name);
  query_session()->advance_phase("/core/login/phases/avatar_menu");

  return;
}
