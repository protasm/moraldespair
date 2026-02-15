inherit "/core/object";

#include <globals.h>

object *phase_stack;
mapping session_data;

#include "login-session-flow.c"
#include "login-session-enter-game.c"

void create() {
  ::create();

  phase_stack = ({});
  session_data = ([]);

  return;
}

void logon() {
  phase_stack = ({});
  session_data = ([]);

  cat(WELCOME_FILE, 1, 1);

  push_phase("/core/login/phases/get_account_name");

  return;
}

void net_dead() {
  set_session_value("disconnected", 1);

  return;
}

void reconnect() {
  set_session_value("disconnected", 0);
  session_write("Reconnected.");

  begin_current_phase();

  return;
}
