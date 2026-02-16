/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/player/player-data.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

object avatar_object;
object account_object;

/* Method Summary:
 * Purpose:
 *   Handles avatar for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns the controlled avatar object when available.
 * Side effects:
 *   None.
 * Returns:
 *   object result from avatar.
 */
object avatar() {
  return avatar_object;
}

/* Method Summary:
 * Purpose:
 *   Handles player for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Compatibility alias returning the controlled avatar object.
 * Side effects:
 *   None.
 * Returns:
 *   object result from player.
 */
object player() {
  return avatar();
}

/* Method Summary:
 * Purpose:
 *   Handles set_avatar for this object.
 * Parameters:
 *   - object new_avatar
 * Approach:
 *   Stores the controlled avatar reference for this interactive player.
 * Side effects:
 *   May mutate object state.
 * Returns:
 *   void result from set_avatar.
 */
void set_avatar(object new_avatar) {
  avatar_object = new_avatar;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles account for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns the current account object, falling back to avatar state.
 * Side effects:
 *   None.
 * Returns:
 *   object result from account.
 */
object account() {
  if (objectp(account_object))
    return account_object;

  if (!objectp(avatar_object))
    return 0;

  if (!function_exists("account", avatar_object))
    return 0;

  return avatar_object->account();
}

/* Method Summary:
 * Purpose:
 *   Handles set_account for this object.
 * Parameters:
 *   - object new_account
 * Approach:
 *   Stores account context for this interactive player.
 * Side effects:
 *   May mutate object state.
 * Returns:
 *   void result from set_account.
 */
void set_account(object new_account) {
  account_object = new_account;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles name for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Resolves display name from the controlled avatar.
 * Side effects:
 *   None.
 * Returns:
 *   string result from name.
 */
string name() {
  if (!objectp(avatar_object))
    return "";

  if (!function_exists("name", avatar_object))
    return "";

  return avatar_object->name();
}

/* Method Summary:
 * Purpose:
 *   Handles is_wizard for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Mirrors wizard status from the controlled avatar.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_wizard.
 */
int is_wizard() {
  if (!objectp(avatar_object))
    return 0;

  if (!function_exists("is_wizard", avatar_object))
    return 0;

  return avatar_object->is_wizard();
}
