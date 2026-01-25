void logon() {
  object player;

  player = new("/core/player");

  exec(player, this_object());

  player->start_session();

  player->move(START_ROOM);

  destruct(this_object());
}
