/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/get_account_name.c.
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
  prompt_line(
    "Enter account name, type 'create' to make a new account, "
    "or 'guest' to play now:"
  );

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
  int unknown_attempts;

  account_name = normalized(input);

  if (require_nonempty_input(input))
    return;

  if (account_name == "create") {
    query_session()->set_session_value("unknown_account_attempts", 0);
    query_session()->advance_phase("/core/login/phases/create_account_name");
    return;
  }

  if (account_name == "guest") {
    query_session()->set_session_value("unknown_account_attempts", 0);
    query_session()->set_session_value("account_name", "guest");
    query_session()->set_session_value("authenticated", 1);
    query_session()->enter_guest_game();
    return;
  }

  if (!ACCOUNT_D->account_exists(account_name)) {
    unknown_attempts = query_session()->query_session_value("unknown_account_attempts");

    if (!intp(unknown_attempts))
      unknown_attempts = 0;

    unknown_attempts += 1;
    query_session()->set_session_value("unknown_account_attempts", unknown_attempts);

    if (unknown_attempts >= 3) {
      query_session()->disconnect_session(
        "That account does not exist.\n"
        "Too many failed account attempts. Please reconnect when ready."
      );
      return;
    }

    write_line("That account does not exist.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("unknown_account_attempts", 0);
  query_session()->set_session_value("account_name", account_name);
  query_session()->set_session_value("authenticated", 0);
  query_session()->advance_phase("/core/login/phases/password_entry");

  return;
}
