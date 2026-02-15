inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_line("Enter account name, or type 'create' to make a new account:");

  return;
}

void handle_input(string input) {
  string account_name;

  account_name = normalized(input);

  if (account_name == "") {
    begin_phase();
    return;
  }

  if (account_name == "create") {
    query_session()->advance_phase("/core/login/phases/create_account_name");
    return;
  }

  if (!ACCOUNT_D->account_exists(account_name)) {
    write_line("That account does not exist.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("account_name", account_name);
  query_session()->set_session_value("authenticated", 0);
  query_session()->advance_phase("/core/login/phases/password_entry");

  return;
}
