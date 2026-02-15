inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_secret("Confirm password:");

  return;
}

void handle_input(string input) {
  string account_name;
  string password;
  string password_hash;
  string display;
  int created;

  if (!stringp(input))
    input = "";

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
