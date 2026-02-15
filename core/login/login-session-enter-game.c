string normalize_value(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

void enter_game(string avatar_name) {
  object account;
  object player;
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

  player->move(start_room);

  if (!objectp(environment(player)))
    player->move(START_ROOM);

  player->show_location(1, 1);

  destruct(this_object());

  return;
}
