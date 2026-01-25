#include <globals.h>

void logon() {
  object player;

  player = new(PLAYER_OB);

  exec(player, this_object());

  player->start_session();

  player->move(START_ROOM);

  destruct(this_object());
}
