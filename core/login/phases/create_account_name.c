inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_line("Choose a new account name:");

  return;
}

void handle_input(string input) {
  string account_name;

  account_name = normalized(input);

  if (account_name == "") {
    begin_phase();
    return;
  }

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
