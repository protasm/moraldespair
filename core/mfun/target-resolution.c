/*
 * Master Summary:
 * Purpose:
 *   Implements shared in-room object target resolution helpers.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/* Method Summary:
 * Purpose:
 *   Handles resolve_environment_target for this object.
 * Parameters:
 *   - object actor, string target
 * Approach:
 *   Resolves a target object from the actor's current environment by
 *   id(), name(), or short() matching.
 * Side effects:
 *   None.
 * Returns:
 *   object result from resolve_environment_target.
 */
object resolve_environment_target(object actor, string target) {
  object env;
  object *contents;
  object candidate;
  string normalized;
  string candidate_name;
  string candidate_short;
  int i;

  if (!objectp(actor))
    return 0;

  if (!stringp(target))
    return 0;

  normalized = lower_case(trim(target));

  if (normalized == "")
    return 0;

  env = environment(actor);

  if (!objectp(env))
    return 0;

  contents = all_inventory(env);

  if (!pointerp(contents) || !sizeof(contents))
    return 0;

  for (i = 0; i < sizeof(contents); i++) {
    candidate = contents[i];

    if (!objectp(candidate))
      continue;

    if (candidate == actor)
      continue;

    if (function_exists("id", candidate))
      if (candidate->id(normalized))
        return candidate;

    candidate_name = "";

    if (function_exists("name", candidate))
      candidate_name = candidate->name();

    if (stringp(candidate_name))
      candidate_name = lower_case(trim(candidate_name));

    if (candidate_name == normalized)
      return candidate;

    candidate_short = "";

    if (function_exists("short", candidate))
      candidate_short = candidate->short();

    if (stringp(candidate_short))
      candidate_short = lower_case(trim(candidate_short));

    if (candidate_short == normalized)
      return candidate;
  }

  return 0;
}
