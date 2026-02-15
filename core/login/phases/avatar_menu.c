/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/avatar_menu.c.
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
 *   Handles show_menu for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for show_menu.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from show_menu.
 */
void show_menu() {
  string account_name;
  string *avatars;
  string avatar_name;
  string last_played_avatar;
  int max_slots;
  int i;

  account_name = normalized(query_session()->query_session_value("account_name"));
  avatars = ACCOUNT_D->players(account_name);
  last_played_avatar = ACCOUNT_D->last_played_player(account_name);
  max_slots = 3;

  if (!pointerp(avatars))
    avatars = ({});

  write_line("Avatars:");

  for (i = 0; i < max_slots; i++) {
    if (i < sizeof(avatars)) {
      avatar_name = avatars[i];

      if (avatar_name == last_played_avatar)
        write_line("  " + (i + 1) + ") " + avatar_name + " (*)");
      else
        write_line("  " + (i + 1) + ") " + avatar_name);
    } else
      write_line("  " + (i + 1) + ") [create new avatar]");
  }

  if (last_played_avatar != "")
    prompt_line("Select slot number, or Enter for (*):");
  else
    prompt_line("Select slot number:");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles register_invalid_selection for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for register_invalid_selection.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from register_invalid_selection.
 */
void register_invalid_selection() {
  int invalid_attempts;

  invalid_attempts = query_session()->query_session_value("avatar_invalid_selection_attempts");

  if (!intp(invalid_attempts))
    invalid_attempts = 0;

  invalid_attempts += 1;
  query_session()->set_session_value("avatar_invalid_selection_attempts", invalid_attempts);

  if (invalid_attempts >= 3) {
    query_session()->disconnect_session(
      "Too many invalid avatar selections.\n"
      "Disconnecting for now. Please reconnect when ready."
    );
  } else {
    write_line("That is not a valid avatar slot.");
    show_menu();
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles select_avatar_by_slot for this object.
 * Parameters:
 *   - int selected_index, string *avatars
 * Approach:
 *   Validates inputs and executes explicit local logic for select_avatar_by_slot.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from select_avatar_by_slot.
 */
void select_avatar_by_slot(int selected_index, string *avatars) {
  int slots_remaining;

  slots_remaining = ACCOUNT_D->player_slots_remaining(
    normalized(query_session()->query_session_value("account_name"))
  );

  query_session()->set_session_value("avatar_invalid_selection_attempts", 0);

  if (selected_index <= sizeof(avatars)) {
    query_session()->set_session_value("selected_avatar_id",
      avatars[selected_index - 1]);
    query_session()->enter_game(avatars[selected_index - 1]);
    return;
  }

  if (slots_remaining > 0) {
    query_session()->push_phase("/core/login/phases/character_creation");
    return;
  }

  write_line("This account has no open avatar slots.");
  show_menu();

  return;
}

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
  show_menu();

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
  string choice;
  string *avatars;
  string last_played_avatar;
  int selected_index;
  int max_slots;

  account_name = normalized(query_session()->query_session_value("account_name"));
  choice = normalized(input);
  avatars = ACCOUNT_D->players(account_name);
  last_played_avatar = ACCOUNT_D->last_played_player(account_name);
  max_slots = 3;

  if (!pointerp(avatars))
    avatars = ({});

  if (choice == "") {
    if (last_played_avatar != "") {
      query_session()->set_session_value("avatar_invalid_selection_attempts", 0);
      query_session()->set_session_value("selected_avatar_id", last_played_avatar);
      query_session()->enter_game(last_played_avatar);
      return;
    }
  }

  if (require_nonempty_input(choice))
    return;

  if (sscanf(choice, "%d", selected_index) != 1) {
    register_invalid_selection();
    return;
  }

  if (selected_index < 1 || selected_index > max_slots) {
    register_invalid_selection();
    return;
  }

  select_avatar_by_slot(selected_index, avatars);

  return;
}
