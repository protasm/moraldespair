inherit "/core/login/phases/base_phase";

#include <globals.h>

void show_menu() {
  string account_name;
  string *avatars;
  int slots_remaining;
  int i;

  account_name = normalized(query_session()->query_session_value("account_name"));
  avatars = ACCOUNT_D->players(account_name);
  slots_remaining = ACCOUNT_D->player_slots_remaining(account_name);

  if (!pointerp(avatars))
    avatars = ({});

  if (sizeof(avatars) == 0 && slots_remaining <= 0) {
    write_line("No avatars are available on this account.");
    query_session()->advance_phase("/core/login/phases/get_account_name");
    return;
  }

  write_line("Avatars:");

  for (i = 0; i < sizeof(avatars); i++)
    write_line("  " + (i + 1) + ") " + avatars[i]);

  if (slots_remaining > 0)
    write_line("  c) Create new avatar");

  if (slots_remaining > 0)
    prompt_line("Select avatar by number/name, or type 'c' to create:");
  else
    prompt_line("Select avatar by number or name:");

  return;
}

void begin_phase() {
  show_menu();

  return;
}

void handle_input(string input) {
  string account_name;
  string choice;
  string *avatars;
  int slots_remaining;
  int selected_index;
  int i;

  account_name = normalized(query_session()->query_session_value("account_name"));
  choice = normalized(input);
  avatars = ACCOUNT_D->players(account_name);
  slots_remaining = ACCOUNT_D->player_slots_remaining(account_name);

  if (!pointerp(avatars))
    avatars = ({});

  if (choice == "") {
    show_menu();
    return;
  }

  if (choice == "c" || choice == "create" || choice == "new") {
    if (slots_remaining > 0) {
      query_session()->push_phase("/core/login/phases/character_creation");
      return;
    }

    write_line("This account has no open avatar slots.");
    show_menu();
    return;
  }

  if (sscanf(choice, "%d", selected_index) == 1) {
    if (selected_index >= 1 && selected_index <= sizeof(avatars)) {
      query_session()->set_session_value("selected_avatar_id",
        avatars[selected_index - 1]);
      query_session()->enter_game(avatars[selected_index - 1]);
      return;
    }
  }

  for (i = 0; i < sizeof(avatars); i++) {
    if (normalized(avatars[i]) == choice) {
      query_session()->set_session_value("selected_avatar_id", avatars[i]);
      query_session()->enter_game(avatars[i]);
      return;
    }
  }

  write_line("That avatar is not on this account.");
  show_menu();

  return;
}
