/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/avatar/avatar-process-input.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
/* Method Summary:
 * Purpose:
 *   Handles can_target_soul_object for this object.
 * Parameters:
 *   - object candidate
 * Approach:
 *   Restricts soul targeting to avatars and NPCs only.
 * Side effects:
 *   None.
 * Returns:
 *   int result from can_target_soul_object.
 */
int can_target_soul_object(object candidate) {
  int is_npc;

  if (!objectp(candidate))
    return 0;

  if (is_avatar(candidate))
    return 1;

  if (!function_exists("is_npc", candidate))
    return 0;

  is_npc = candidate->is_npc();

  if (!intp(is_npc) || !is_npc)
    return 0;

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_apply_template for this object.
 * Parameters:
 *   - string template, string actor_name, string target_name
 * Approach:
 *   Expands actor and target placeholders in emote templates.
 * Side effects:
 *   None.
 * Returns:
 *   string result from soul_apply_template.
 */
string soul_apply_template(string template, string actor_name, string target_name) {
  string expanded;

  if (!stringp(template) || template == "")
    return "";

  expanded = template;
  expanded = replace_string(expanded, "%ACTOR%", actor_name);
  expanded = replace_string(expanded, "%TARGET%", target_name);

  return expanded;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_emit_to for this object.
 * Parameters:
 *   - object recipient, string text
 * Approach:
 *   Routes soul message text to avatars and NPCs in a compatible way.
 * Side effects:
 *   Sends message text to recipients.
 * Returns:
 *   void result from soul_emit_to.
 */
void soul_emit_to(object recipient, string text) {
  if (!objectp(recipient))
    return;

  if (!stringp(text) || text == "")
    return;

  if (is_avatar(recipient)) {
    avatar_experience(recipient, text + "\n");

    return;
  }

  tell_object(recipient, text + "\n");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_broadcast for this object.
 * Parameters:
 *   - object actor, object target, string target_text, string room_text
 * Approach:
 *   Sends the target-specific text to the target and room text to other
 *   in-room avatars and NPCs.
 * Side effects:
 *   Sends message text to recipients in actor's environment.
 * Returns:
 *   void result from soul_broadcast.
 */
void soul_broadcast(object actor, object target, string target_text,
  string room_text) {
  object env;
  object *contents;
  object observer;
  int i;

  if (!objectp(actor))
    return;

  env = environment(actor);

  if (!objectp(env))
    return;

  contents = all_inventory(env);

  if (!pointerp(contents) || !sizeof(contents))
    return;

  for (i = 0; i < sizeof(contents); i++) {
    observer = contents[i];

    if (!objectp(observer))
      continue;

    if (observer == actor)
      continue;

    if (!can_target_soul_object(observer))
      continue;

    if (observer == target) {
      soul_emit_to(observer, target_text);

      continue;
    }

    soul_emit_to(observer, room_text);
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_actor_name for this object.
 * Parameters:
 *   - object actor
 * Approach:
 *   Resolves actor display name used in third-person emote messages.
 * Side effects:
 *   None.
 * Returns:
 *   string result from soul_actor_name.
 */
string soul_actor_name(object actor) {
  string actor_name;

  if (!objectp(actor))
    return "Someone";

  actor_name = "";

  if (function_exists("name", actor))
    actor_name = actor->name();

  if (!stringp(actor_name) || actor_name == "")
    actor_name = "Someone";

  return actor_name;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_third_person_verb for this object.
 * Parameters:
 *   - string verb
 * Approach:
 *   Produces a simple third-person singular inflection for fallback text.
 * Side effects:
 *   None.
 * Returns:
 *   string result from soul_third_person_verb.
 */
string soul_third_person_verb(string verb) {
  int len;
  string last_char;
  string tail_two;

  if (!stringp(verb) || verb == "")
    return "does";

  len = strlen(verb);
  last_char = verb[<1..];

  if (len >= 2)
    tail_two = verb[<2..];
  else
    tail_two = verb;

  if (last_char == "s" || last_char == "x" || last_char == "z")
    return verb + "es";

  if (last_char == "o")
    return verb + "es";

  if (tail_two == "ch" || tail_two == "sh")
    return verb + "es";

  return verb + "s";
}

/* Method Summary:
 * Purpose:
 *   Handles soul_target_name for this object.
 * Parameters:
 *   - object target
 * Approach:
 *   Resolves a display-safe name for emote target text.
 * Side effects:
 *   None.
 * Returns:
 *   string result from soul_target_name.
 */
string soul_target_name(object target) {
  string target_name;

  if (!objectp(target))
    return "";

  target_name = "";

  if (function_exists("name", target))
    target_name = target->name();

  if (!stringp(target_name) || target_name == "")
    target_name = "someone";

  return target_name;
}

/* Method Summary:
 * Purpose:
 *   Handles handle_soul_input for this object.
 * Parameters:
 *   - string verb, string arg
 * Approach:
 *   Looks up JSON-defined emotes and optionally resolves in-room player
 *   or NPC targets.
 * Side effects:
 *   Writes response text to the avatar.
 * Returns:
 *   int result from handle_soul_input.
 */
int handle_soul_input(string verb, string arg) {
  mapping emote;
  object avatar;
  object target;
  string normalized_arg;
  string untargeted_actor;
  string untargeted_room;
  string targeted_actor;
  string targeted_target;
  string targeted_room;
  string missing_target_text;
  string actor_name;
  string target_name;
  string actor_text;
  string room_text;
  string target_text;
  string third_person_verb;

  if (!stringp(verb) || verb == "")
    return 0;

  emote = soul_emote(verb);

  if (!mapp(emote))
    return 0;

  avatar = this_object();
  actor_name = soul_actor_name(avatar);
  third_person_verb = soul_third_person_verb(verb);

  untargeted_actor = emote["untargeted_actor"];
  untargeted_room = emote["untargeted_room"];
  targeted_actor = emote["targeted_actor"];
  targeted_target = emote["targeted_target"];
  targeted_room = emote["targeted_room"];
  missing_target_text = emote["missing_target"];

  if (!stringp(untargeted_actor) || untargeted_actor == "")
    untargeted_actor = emote["untargeted"];

  if (!stringp(targeted_actor) || targeted_actor == "")
    targeted_actor = emote["targeted"];

  if (!stringp(missing_target_text) || missing_target_text == "")
    missing_target_text = capitalize(verb) + " at who?";

  if (!stringp(arg))
    arg = "";

  normalized_arg = lower_case(trim(arg));

  if (sizeof(normalized_arg) >= 3 && normalized_arg[0..2] == "at ")
    normalized_arg = trim(normalized_arg[3..]);

  if (normalized_arg == "") {
    if (!stringp(untargeted_actor) || untargeted_actor == "")
      untargeted_actor = "You " + verb + ".";

    if (!stringp(untargeted_room) || untargeted_room == "")
      untargeted_room = "%ACTOR% " + third_person_verb + ".";

    actor_text = soul_apply_template(untargeted_actor, actor_name, "");
    room_text = soul_apply_template(untargeted_room, actor_name, "");

    avatar_experience(avatar, actor_text + "\n");
    soul_broadcast(avatar, 0, "", room_text);

    return 1;
  }

  target = resolve_environment_target(avatar, normalized_arg);

  if (!can_target_soul_object(target)) {
    avatar_experience(avatar, missing_target_text + "\n");

    return 1;
  }

  if (!stringp(targeted_actor) || targeted_actor == "")
    targeted_actor = "You " + verb + " at %TARGET%.";

  if (!stringp(targeted_target) || targeted_target == "")
    targeted_target = "%ACTOR% " + third_person_verb + " at you.";

  if (!stringp(targeted_room) || targeted_room == "")
    targeted_room = "%ACTOR% " + third_person_verb + " at %TARGET%.";

  target_name = soul_target_name(target);
  actor_text = soul_apply_template(targeted_actor, actor_name, target_name);
  target_text = soul_apply_template(targeted_target, actor_name, target_name);
  room_text = soul_apply_template(targeted_room, actor_name, target_name);

  avatar_experience(avatar, actor_text + "\n");
  soul_broadcast(avatar, target, target_text, room_text);

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles process_input for this object.
 * Parameters:
 *   - string raw
 * Approach:
 *   Validates inputs and executes explicit local logic for process_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from process_input.
 */
string process_input(string raw) {
  object combat_daemon;
  object command;
  object avatar, env;
  object link_cache;
  string verb, arg, command_path;

  // Ignore non-string input so command parsing does not explode.
  if (!stringp(raw))
    return "";

  // Normalize whitespace before any parsing.
  raw = trim(raw);

  // Drop empty input lines early.
  if (raw == "")
    return "";

  if (function_exists("query_in_combat", this_object())) {
    if (this_object()->query_in_combat()) {
      combat_daemon = find_object(COMBAT_D);

      if (!objectp(combat_daemon))
        combat_daemon = load_object(COMBAT_D);

      if (objectp(combat_daemon) && function_exists("handle_input", combat_daemon)) {
        combat_daemon->handle_input(this_object(), raw);

        return "";
      }
    }
  }

  // Split verb from argument, defaulting to empty arg.
  if (sscanf(raw, "%s %s", verb, arg) != 2) {
    verb = raw;
    arg = "";
  }

  // Commands are case-insensitive, keep the verb normalized.
  verb = lower_case(verb);

  // Look for core command implementations first.
  command_path = "/core/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // If the command handles the input, swallow the line.
    if (command->main(arg))
      return "";
    else
      return raw;
  }

  // Look for wizard-only commands next.
  if (wizardp(this_object())) {
    command_path = "/core/command/wizard/" + verb;

    if (file_size(command_path + ".c") >= 0) {
      command = load_object(command_path);

      if (command->main(arg))
        return "";
      else
        return raw;
    }
  }

  // Fall back to chapter-specific actions if core commands miss.
  command_path = "/chapter/prologue/action/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // Let chapter actions decide whether the input is consumed.
    if (command->main(arg))
      return "";
    else
      return raw;
  }

  if (handle_soul_input(verb, arg))
    return "";

  // Try the "go" action as a last-resort movement handler.
  command_path = "/chapter/prologue/action/go";

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    // Pass the verb as the direction when "go" is the fallback.
    if (command->main(verb))
      return "";
  }

  // Begin room-specific action matching.
  avatar = this_object();
  env = environment(avatar);

  if (objectp(env)) {
    if (function_exists("link_cache", env))
      link_cache = env->link_cache();

    if (objectp(link_cache) && function_exists("handle_input", link_cache)) {
      if (link_cache->handle_input(avatar, verb, arg))
        return "";
    }
  }

  if (command(raw))
    return "";

  // Let unmatched input fall through to default driver handling.
  return raw;
}
