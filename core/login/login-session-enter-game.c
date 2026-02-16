/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/login-session-enter-game.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/* Method Summary:
 * Purpose:
 *   Handles normalize_value for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_value.
 */
string normalize_value(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

/* Method Summary:
 * Purpose:
 *   Handles wizard_virtual_debug for this object.
 * Parameters:
 *   - object avatar, string message
 * Approach:
 *   Validates inputs and executes explicit local logic for wizard_virtual_debug.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from wizard_virtual_debug.
 */
void wizard_virtual_debug(object avatar, string message) {
  string line;

  if (!objectp(avatar))
    return;

  if (!stringp(message) || message == "")
    return;

  line = ctime(time()) + " login enter_game " + message + "\n";
  write_file("/log/virtual_room_debug", line);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles announce_avatar_entry for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Validates inputs and executes explicit local logic for announce_avatar_entry.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from announce_avatar_entry.
 */
void announce_avatar_entry(object avatar) {
  object room;

  if (!objectp(avatar))
    return;

  room = environment(avatar);

  if (!objectp(room))
    return;

  EXPERIENCE_D->emit_avatar_presence_arrival(avatar, room);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles enter_game for this object.
 * Parameters:
 *   - string selected_avatar_name
 * Approach:
 *   Validates inputs and executes explicit local logic for enter_game.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from enter_game.
 */
void enter_game(string selected_avatar_name) {
  object account;
  object player;
  object avatar;
  object current_room;
  int brief;
  string entry_avatar_name;
  string account_name;
  string start_room;

  account_name = normalize_value(session_data["account_name"]);
  selected_avatar_name = capitalize(normalize_value(selected_avatar_name));

  if (account_name == "" || selected_avatar_name == "") {
    session_write("Unable to enter game.");
    return;
  }

  account = new(ACCOUNT_OB);
  player = new(PLAYER_OB);
  avatar = new(AVATAR_OB);

  account->set_username(account_name);
  player->set_account(account);
  player->set_avatar(avatar);
  avatar->set_account(account);
  avatar->set_player(player);
  avatar->set_name(selected_avatar_name);
  entry_avatar_name = avatar_name(avatar);

  if (!stringp(entry_avatar_name) || entry_avatar_name == "")
    entry_avatar_name = selected_avatar_name;

  brief = avatar->brief();
  avatar->set_brief(brief);

  ACCOUNT_D->record_player_login(account_name, entry_avatar_name);

  if (!exec(player, this_object())) {
    session_write("Connection transfer failed. Please reconnect.");
    destruct(player);
    destruct(avatar);
    destruct(account);
    return;
  }

  player->check_wizard();
  cat(MOTD_FILE, 1, 1);

  start_room = CHAPTER_D->resolve_avatar_start_room(avatar);

  if (!stringp(start_room) || start_room == "")
    start_room = START_ROOM;

  if (sizeof(start_room) > 2 && start_room[<2..<1] == ".c")
    start_room = start_room[0..<3];

  wizard_virtual_debug(avatar, "initial start_room resolved: " + start_room);

  avatar->move(start_room);
  current_room = environment(avatar);

  if (!objectp(current_room)) {
    wizard_virtual_debug(avatar, "initial move failed, fallback to START_ROOM");
    avatar->move(START_ROOM);
    current_room = environment(avatar);
  }

  if (objectp(current_room))
    wizard_virtual_debug(avatar, "spawned in room object: " + file_name(current_room));
  else
    wizard_virtual_debug(avatar, "spawn failed: no room environment after fallback");

  if (objectp(current_room))
    announce_avatar_entry(avatar);

  player->show_location(1, 1);

  destruct(this_object());

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles enter_guest_game for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Creates an ephemeral guest avatar and enters play without account auth.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from enter_guest_game.
 */
void enter_guest_game() {
  object account;
  object player;
  object avatar;
  object current_room;
  string guest_name;
  string account_name;

  account_name = normalize_value(session_data["account_name"]);

  if (account_name == "")
    account_name = "guest";

  guest_name = "Guest";

  account = new(ACCOUNT_OB);
  player = new(PLAYER_OB);
  avatar = new(AVATAR_OB);

  account->set_username(account_name);
  player->set_account(account);
  player->set_avatar(avatar);
  avatar->set_account(account);
  avatar->set_player(player);
  avatar->set_name(guest_name);

  if (!exec(player, this_object())) {
    session_write("Connection transfer failed. Please reconnect.");
    destruct(player);
    destruct(avatar);
    destruct(account);
    return;
  }

  player->check_wizard();
  cat(MOTD_FILE, 1, 1);

  avatar->move(START_ROOM);
  current_room = environment(avatar);

  if (objectp(current_room))
    announce_avatar_entry(avatar);

  player->show_location(1, 1);

  destruct(this_object());

  return;
}
