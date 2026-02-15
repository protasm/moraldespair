inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_secret("Password:");

  return;
}

void handle_input(string input) {
  string account_name;
  string password_hash;
  string attempt_hash;

  if (!stringp(input))
    input = "";

  account_name = normalized(query_session()->query_session_value("account_name"));

  if (account_name == "") {
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  password_hash = ACCOUNT_D->password_hash(account_name);

  if (!stringp(password_hash) || password_hash == "") {
    write_line("Password incorrect.");
    begin_phase();
    return;
  }

  attempt_hash = crypt(input, password_hash);

  if (attempt_hash != password_hash) {
    write_line("Password incorrect.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("authenticated", 1);
  ACCOUNT_D->record_login(account_name);
  query_session()->advance_phase("/core/login/phases/avatar_menu");

  return;
}
