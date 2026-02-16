/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/mfun/identity.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "identity.h"
 */

#include "identity.h"

/* Method Summary:
 * Purpose:
 *   Handles current_avatar for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Resolves the active in-game avatar object for the current command
 *   context and gracefully handles wrapper command objects.
 * Side effects:
 *   None.
 * Returns:
 *   object result from current_avatar.
 */
object current_avatar() {
  object active;
  object avatar;

  active = this_player();

  if (!objectp(active))
    active = previous_object();

  if (!objectp(active))
    return 0;

  if (function_exists("avatar", active)) {
    avatar = active->avatar();

    if (objectp(avatar))
      return avatar;
  }

  if (function_exists("player", active)) {
    avatar = active->player();

    if (objectp(avatar))
      return avatar;
  }

  if (is_avatar(active))
    return active;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles current_session for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns the current interactive object from the FluffOS driver.
 * Side effects:
 *   None.
 * Returns:
 *   object result from current_session.
 */
object current_session() {
  return this_interactive();
}

/* Method Summary:
 * Purpose:
 *   Handles connected_avatars for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns connected interactive objects as provided by the driver.
 * Side effects:
 *   None.
 * Returns:
 *   object result from connected_avatars.
 */
object *connected_avatars() {
  object *online;
  object online_object;
  object controlled_avatar;
  object *avatars;
  int i;

  online = users();

  if (!pointerp(online))
    return ({});

  avatars = ({});

  for (i = 0; i < sizeof(online); i++) {
    online_object = online[i];

    if (!objectp(online_object))
      continue;

    if (function_exists("player", online_object)) {
      controlled_avatar = online_object->player();

      if (!is_avatar(controlled_avatar))
        continue;

      avatars += ({ controlled_avatar });

      continue;
    }

    if (!is_avatar(online_object))
      continue;

    avatars += ({ online_object });
  }

  return avatars;
}

/* Method Summary:
 * Purpose:
 *   Handles is_avatar for this object.
 * Parameters:
 *   - object obj
 * Approach:
 *   Validates that an object supports the expected avatar interface.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_avatar.
 */
int is_avatar(object obj) {
  int living_state;

  if (!objectp(obj))
    return 0;

  if (!function_exists("account", obj))
    return 0;

  if (!function_exists("name", obj))
    return 0;

  if (!function_exists("is_living", obj))
    return 0;

  living_state = obj->is_living();

  if (!intp(living_state) || !living_state)
    return 0;

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles is_connected_avatar for this object.
 * Parameters:
 *   - object obj
 * Approach:
 *   Confirms the object matches avatar semantics and has an active
 *   interactive connection.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_connected_avatar.
 */
int is_connected_avatar(object obj) {
  object controller;

  controller = avatar_controller(obj);

  if (!objectp(controller))
    return 0;

  return userp(controller);
}

/* Method Summary:
 * Purpose:
 *   Handles avatar_account for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Returns the account object associated with an avatar object.
 * Side effects:
 *   None.
 * Returns:
 *   object result from avatar_account.
 */
object avatar_account(object avatar) {
  object account;

  if (!is_avatar(avatar))
    return 0;

  account = avatar->account();

  if (!objectp(account))
    return 0;

  return account;
}

/* Method Summary:
 * Purpose:
 *   Handles avatar_controller for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Resolves the interactive player controlling an avatar object.
 * Side effects:
 *   None.
 * Returns:
 *   object result from avatar_controller.
 */
object avatar_controller(object avatar) {
  object controller;

  if (!is_avatar(avatar))
    return 0;

  if (function_exists("player", avatar)) {
    controller = avatar->player();

    if (objectp(controller) && userp(controller))
      return controller;
  }

  if (userp(avatar))
    return avatar;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles avatar_experience for this object.
 * Parameters:
 *   - object avatar, string text
 * Approach:
 *   Routes textual experience through avatar->experience(...) when
 *   available, with controller fallback for compatibility.
 * Side effects:
 *   May write text to a connected controller object.
 * Returns:
 *   int result from avatar_experience.
 */
int avatar_experience(object avatar, string text) {
  object controller;
  mapping event;

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(text))
    return 0;

  if (function_exists("experience", avatar)) {
    event = ([
      "type" : "text",
      "text" : text
    ]);
    avatar->experience(event);

    return 1;
  }

  controller = avatar_controller(avatar);

  if (!objectp(controller))
    return 0;

  tell_object(controller, text);

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles avatar_name for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Returns display name text for an avatar object.
 * Side effects:
 *   None.
 * Returns:
 *   string result from avatar_name.
 */
string avatar_name(object avatar) {
  string name;

  if (!is_avatar(avatar))
    return "";

  name = avatar->name();

  if (!stringp(name))
    return "";

  return name;
}

/* Method Summary:
 * Purpose:
 *   Handles avatar_id for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Normalizes avatar identity text for stable comparisons.
 * Side effects:
 *   None.
 * Returns:
 *   string result from avatar_id.
 */
string avatar_id(object avatar) {
  string id;

  id = avatar_name(avatar);

  if (!stringp(id) || id == "")
    return "";

  return lower_case(trim(id));
}

/* Method Summary:
 * Purpose:
 *   Handles session_account_name for this object.
 * Parameters:
 *   - object session
 * Approach:
 *   Reads normalized account name from a login session object.
 * Side effects:
 *   None.
 * Returns:
 *   string result from session_account_name.
 */
string session_account_name(object session) {
  string account_name;

  if (!objectp(session))
    return "";

  if (!function_exists("query_session_value", session))
    return "";

  account_name = session->query_session_value("account_name");

  if (!stringp(account_name) || account_name == "")
    return "";

  return lower_case(trim(account_name));
}

/* Method Summary:
 * Purpose:
 *   Handles session_selected_avatar for this object.
 * Parameters:
 *   - object session
 * Approach:
 *   Reads normalized selected avatar identifier from a login session.
 * Side effects:
 *   None.
 * Returns:
 *   string result from session_selected_avatar.
 */
string session_selected_avatar(object session) {
  string avatar;

  if (!objectp(session))
    return "";

  if (!function_exists("query_session_value", session))
    return "";

  avatar = session->query_session_value("selected_avatar_id");

  if (!stringp(avatar) || avatar == "")
    return "";

  return lower_case(trim(avatar));
}

/* Method Summary:
 * Purpose:
 *   Handles session_authenticated for this object.
 * Parameters:
 *   - object session
 * Approach:
 *   Reads login authentication state from a session object.
 * Side effects:
 *   None.
 * Returns:
 *   int result from session_authenticated.
 */
int session_authenticated(object session) {
  mixed authenticated;

  if (!objectp(session))
    return 0;

  if (!function_exists("query_session_value", session))
    return 0;

  authenticated = session->query_session_value("authenticated");

  if (!intp(authenticated))
    return 0;

  if (!authenticated)
    return 0;

  return 1;
}
