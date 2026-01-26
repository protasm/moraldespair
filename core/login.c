#include <globals.h>

void logon() {
  object player;

  player = new(PLAYER_OB);

  exec(player, this_object());

  //cat("/etc/motd");

  player->move(START_ROOM);
  player->show_location();

  player->start_session();

  destruct(this_object());
}
