/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/player/player.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include "player-data.c"
 *   - #include "player-process-input.c"
 */

inherit "/core/object/object";

#include <globals.h>
#include "player-data.c"
#include "player-process-input.c"

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Initializes the interactive player controller.
 * Side effects:
 *   Enables command processing and heartbeat callbacks.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  enable_commands();
  set_heart_beat(1);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles heart_beat for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Keeps default heartbeat behavior explicit for future extension.
 * Side effects:
 *   None.
 * Returns:
 *   void result from heart_beat.
 */
void heart_beat() {
  ::heart_beat();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles is_living for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Player controllers are transport/session objects, not world entities.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_living.
 */
int is_living() {
  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles check_wizard for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Enables wizard commands when the controlled avatar has wizard access.
 * Side effects:
 *   May enable wizard privileges on this interactive object.
 * Returns:
 *   void result from check_wizard.
 */
void check_wizard() {
  if (!is_wizard())
    return;

  enable_wizard();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles show_location for this object.
 * Parameters:
 *   - int force_verbose, int show_path
 * Approach:
 *   Delegates room display to the controlled avatar.
 * Side effects:
 *   Writes room information to the interactive player.
 * Returns:
 *   void result from show_location.
 */
void show_location(int force_verbose, int show_path) {
  if (!objectp(avatar_object)) {
    write("System error: no active avatar context for location display.\n");

    return;
  }

  if (!function_exists("show_location", avatar_object)) {
    write("System error: avatar object missing show_location handler.\n");

    return;
  }

  avatar_object->show_location(force_verbose, show_path);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles deliver_experience for this object.
 * Parameters:
 *   - mapping event
 * Approach:
 *   Delivers avatar experience payloads to the interactive player.
 * Side effects:
 *   Writes text to the controlling connection.
 * Returns:
 *   void result from deliver_experience.
 */
void deliver_experience(mapping event) {
  string source;
  string text;
  int in_combat;

  if (!mapp(event))
    return;

  in_combat = 0;

  if (objectp(avatar_object) && function_exists("query_in_combat", avatar_object))
    in_combat = avatar_object->query_in_combat();

  if (in_combat) {
    source = event["source"];

    if (!stringp(source) || source != "combat")
      return;
  }

  text = event["text"];

  if (!stringp(text) || text == "")
    return;

  tell_object(this_object(), wrap_text(text));

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles remove for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Ensures controlled avatar is torn down with the interactive player.
 * Side effects:
 *   Destroys both runtime objects when present.
 * Returns:
 *   void result from remove.
 */
void remove() {
  if (objectp(avatar_object))
    avatar_object->remove();

  ::remove();

  return;
}

void catch_tell(string message) { return; }
void gmcp(string message) { return; }
void gmcp_enable(int enabled) { return; }
void logon() { return; }
void msdp(string message) { return; }
void msdp_enable(int enabled) { return; }
void msp_enable(int enabled) { return; }
void mxp_enable(int enabled) { return; }
void mxp_tag(string message) { return; }
void net_dead() { return; }
void receive_ed(string message) { return; }
void receive_environ(string message) { return; }
void receive_snoop(string message) { return; }
void telnet_suboption(int option, string message) { return; }
void terminal_colour_replace(string message) { return; }
void terminal_type(string message) { return; }
void window_size(int width, int height) { return; }
void write_prompt() {
  if (objectp(avatar_object) && function_exists("query_in_combat", avatar_object)) {
    if (avatar_object->query_in_combat())
      return;
  }

  if (objectp(avatar_object) && function_exists("query_awaiting_combat_input", avatar_object)) {
    if (avatar_object->query_awaiting_combat_input())
      return;
  }

  write(PLAYER_PROMPT);

  return;
}
void zmp(string message) { return; }
