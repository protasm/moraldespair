inherit "/core/login/phases/base_phase";

#include <globals.h>

void begin_phase() {
  prompt_line("Enter a name for your new avatar:");

  return;
}

void handle_input(string input) {
  string account_name;
  string avatar_name;
  int slots_remaining;
  int created;

  account_name = normalized(query_session()->query_session_value("account_name"));
  avatar_name = normalized(input);
  slots_remaining = ACCOUNT_D->player_slots_remaining(account_name);

  if (account_name == "") {
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  if (slots_remaining <= 0) {
    write_line("This account has no open avatar slots.");
    query_session()->pop_phase();
    return;
  }

  if (avatar_name == "") {
    begin_phase();
    return;
  }

  if (contains_reserved(avatar_name)) {
    write_line("That avatar name is not allowed.");
    begin_phase();
    return;
  }

  if (!is_valid_name(avatar_name)) {
    write_line("Avatar names must be one word of 3-20 letters.");
    begin_phase();
    return;
  }

  if (ACCOUNT_D->player_exists(account_name, avatar_name)) {
    write_line("That avatar already exists on this account.");
    begin_phase();
    return;
  }

  avatar_name = display_name(avatar_name);
  created = ACCOUNT_D->add_player(account_name, avatar_name);

  if (!created) {
    write_line("Unable to create avatar right now.");
    begin_phase();
    return;
  }

  query_session()->set_session_value("selected_avatar_id", avatar_name);
  query_session()->enter_game(avatar_name);

  return;
}
