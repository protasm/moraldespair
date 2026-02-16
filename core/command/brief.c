/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/brief.c.
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

  set_category("General");
  set_help_text(
    "Usage: brief\n"
    "Toggle brief mode for room descriptions.\n"
  );
}

/* Method Summary:
 * Purpose:
 *   Handles main for this object.
 * Parameters:
 *   - string arg
 * Approach:
 *   Validates inputs and executes explicit local logic for main.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from main.
 */
int main(string arg) {
  object avatar;
  int enabled;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  enabled = avatar->toggle_brief();

  if (enabled)
    write("Brief mode enabled.\n");
  else
    write("Verbose mode enabled.\n");

  return 1;
}
