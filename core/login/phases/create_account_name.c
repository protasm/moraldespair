/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/create_account_name.c.
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
  prompt_line("Choose a new account name:");

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

  account_name = normalized(input);

  if (require_nonempty_input(input))
    return;

  if (contains_reserved(account_name)) {
    write_line("That account name is not allowed.");
    begin_phase();
    return;
  }

  if (!is_valid_name(account_name)) {
    write_line("Account names must be one word of 3-20 letters.");
    begin_phase();
    return;
  }

  if (ACCOUNT_D->account_exists(account_name)) {
    write_line("That account name is already in use.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("account_name", account_name);
  query_session()->advance_phase("/core/login/phases/create_account_password");

  return;
}
