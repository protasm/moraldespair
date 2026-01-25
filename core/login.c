void logon() {
  object player;

  player = new("/core/player");

  exec(player, this_object());

  player->start_session();

  destruct(this_object());
}
