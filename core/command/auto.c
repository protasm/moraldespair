/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/auto.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 */

inherit "/core/command/command";

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

  set_category("Combat");
  set_help_text(
    "Usage: auto\n"
    "Toggle automatic combat action selection.\n"
  );
}

/* Method Summary:
 * Purpose:
 *   Handles main for this object.
 * Parameters:
 *   - string arg
 * Approach:
 *   Toggles persisted avatar auto-combat mode and reports new state.
 * Side effects:
 *   Persists player setting data.
 * Returns:
 *   int result from main.
 */
int main(string arg) {
  object avatar;
  int enabled;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  enabled = avatar->toggle_auto_combat();

  if (enabled)
    write("Auto-combat enabled.\n");
  else
    write("Auto-combat disabled.\n");

  return 1;
}
