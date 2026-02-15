/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/login_session.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include <globals.h>
 *   - #include "login-session-flow.c"
 *   - #include "login-session-enter-game.c"
 */

inherit "/core/object/object";

#include <globals.h>

object *phase_stack;
mapping session_data;

#include "login-session-flow.c"
#include "login-session-enter-game.c"

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  phase_stack = ({});
  session_data = ([]);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles logon for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for logon.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from logon.
 */
void logon() {
  phase_stack = ({});
  session_data = ([]);

  cat(WELCOME_FILE, 1, 1);

  push_phase("/core/login/phases/get_account_name");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles net_dead for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for net_dead.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from net_dead.
 */
void net_dead() {
  set_session_value("disconnected", 1);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles reconnect for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for reconnect.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from reconnect.
 */
void reconnect() {
  set_session_value("disconnected", 0);
  session_write("Reconnected.");

  begin_current_phase();

  return;
}
