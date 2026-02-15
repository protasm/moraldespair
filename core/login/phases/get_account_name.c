inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_line("Enter account name, or type 'create' to make a new account:");

  return;
}

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
