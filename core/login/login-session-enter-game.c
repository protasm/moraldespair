string normalize_value(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

void wizard_virtual_debug(object player, string message) {
  string line;
  int is_wizard_player;

  if (!objectp(player))
    return;

  if (!stringp(message) || message == "")
    return;

  is_wizard_player = 0;

  if (wizardp(player))
    is_wizard_player = 1;
  else if (function_exists("is_wizard", player) && player->is_wizard())
    is_wizard_player = 1;

  if (!is_wizard_player)
    return;

  line = ctime(time()) + " login enter_game " + message + "\n";
  write_file("/log/virtual_room_debug", line);
  tell_object(player, "[virtual-debug] " + message + "\n");

  return;
}

void enter_game(string avatar_name) {
  object account;
  object player;
  object current_room;
  int brief;
  string account_name;
  string start_room;

  account_name = normalize_value(session_data["account_name"]);
  avatar_name = capitalize(normalize_value(avatar_name));

  if (account_name == "" || avatar_name == "") {
    session_write("Unable to enter game.");
    return;
  }

  account = new(ACCOUNT_OB);
  player = new(PLAYER_OB);

  account->set_username(account_name);
  player->set_account(account);
  player->set_name(avatar_name);

  brief = player->brief();
  player->set_brief(brief);

  ACCOUNT_D->record_player_login(account_name, avatar_name);

  if (!exec(player, this_object())) {
    session_write("Connection transfer failed. Please reconnect.");
    destruct(player);
    destruct(account);
    return;
  }

  player->check_wizard();
  cat(MOTD_FILE, 1, 1);

  start_room = CHAPTER_D->resolve_player_start_room(player);

  if (!stringp(start_room) || start_room == "")
    start_room = START_ROOM;

  if (sizeof(start_room) > 2 && start_room[<2..<1] == ".c")
    start_room = start_room[0..<3];

  wizard_virtual_debug(player, "initial start_room resolved: " + start_room);

  player->move(start_room);
  current_room = environment(player);

  if (!objectp(current_room)) {
    wizard_virtual_debug(player, "initial move failed, fallback to START_ROOM");
    player->move(START_ROOM);
    current_room = environment(player);
  }

  if (objectp(current_room))
    wizard_virtual_debug(player, "spawned in room object: " + file_name(current_room));
  else
    wizard_virtual_debug(player, "spawn failed: no room environment after fallback");

  player->show_location(1, 1);

  destruct(this_object());

  return;
}
