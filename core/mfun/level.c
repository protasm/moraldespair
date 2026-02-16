/*
 * Master Summary:
 * Purpose:
 *   Implements shared numeric level helpers for living entities.
 * Approach:
 *   Centralizes conservative level validation with a minimum of 1.
 * Dependencies:
 *   - none
 */

/* Method Summary:
 * Purpose:
 *   Handles normalize_level_value for this object.
 * Parameters:
 *   - mixed raw_level
 * Approach:
 *   Coerces level-like values to a valid numeric level floor of 1.
 * Side effects:
 *   None.
 * Returns:
 *   int result from normalize_level_value.
 */
int normalize_level_value(mixed raw_level) {
  int level;

  if (!intp(raw_level))
    return 1;

  level = raw_level;

  if (level < 1)
    level = 1;

  return level;
}

/* Method Summary:
 * Purpose:
 *   Handles level_name_label for this object.
 * Parameters:
 *   - string entity_name, mixed raw_level
 * Approach:
 *   Produces a stable "Name (level)" label for living entities.
 * Side effects:
 *   None.
 * Returns:
 *   string result from level_name_label.
 */
string level_name_label(string entity_name, mixed raw_level) {
  int level;

  if (!stringp(entity_name) || trim(entity_name) == "")
    entity_name = "Unknown";
  else
    entity_name = trim(entity_name);

  level = normalize_level_value(raw_level);

  return entity_name + " (" + level + ")";
}

/* Method Summary:
 * Purpose:
 *   Handles level_suffix_for_observer for this object.
 * Parameters:
 *   - mixed raw_target_level, mixed raw_observer_level
 * Approach:
 *   Produces target level visibility suffix based on observer delta.
 * Side effects:
 *   None.
 * Returns:
 *   string result from level_suffix_for_observer.
 */
string level_suffix_for_observer(mixed raw_target_level, mixed raw_observer_level) {
  int target_level;
  int observer_level;
  int level_delta;

  target_level = normalize_level_value(raw_target_level);
  observer_level = normalize_level_value(raw_observer_level);
  level_delta = target_level - observer_level;

  if (level_delta <= 0)
    return "" + target_level;

  if (level_delta <= 2)
    return "?";

  if (level_delta <= 9)
    return "!";

  return "!!";
}

/* Method Summary:
 * Purpose:
 *   Handles observer_level_value for this object.
 * Parameters:
 *   - object observer
 * Approach:
 *   Resolves observer level from avatar or controlling player objects.
 * Side effects:
 *   None.
 * Returns:
 *   int result from observer_level_value.
 */
int observer_level_value(object observer) {
  object avatar;
  int observer_level;

  observer_level = 1;

  if (!objectp(observer))
    return observer_level;

  if (function_exists("query_level", observer))
    observer_level = observer->query_level();
  else if (function_exists("avatar", observer)) {
    avatar = observer->avatar();

    if (objectp(avatar) && function_exists("query_level", avatar))
      observer_level = avatar->query_level();
  }

  return normalize_level_value(observer_level);
}

/* Method Summary:
 * Purpose:
 *   Handles level_name_label_for_observer for this object.
 * Parameters:
 *   - string entity_name, mixed raw_target_level, object observer
 * Approach:
 *   Produces "Name (suffix)" labels based on observer visibility rules.
 * Side effects:
 *   None.
 * Returns:
 *   string result from level_name_label_for_observer.
 */
string level_name_label_for_observer(string entity_name, mixed raw_target_level, object observer) {
  string suffix;
  int observer_level;

  if (!stringp(entity_name) || trim(entity_name) == "")
    entity_name = "Unknown";
  else
    entity_name = trim(entity_name);

  observer_level = observer_level_value(observer);
  suffix = level_suffix_for_observer(raw_target_level, observer_level);

  return entity_name + " (" + suffix + ")";
}
