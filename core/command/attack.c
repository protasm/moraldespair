/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/attack.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 *   - #include <globals.h>
 */

inherit "/core/command/command";

#include <globals.h>

void create() {
  ::create();

  set_category("Combat");
  set_help_text(
    "Usage: attack <target>\n"
    "Begin turn-based combat with a nearby NPC.\n"
  );
}

int main(string arg) {
  object avatar;
  object target;
  string normalized;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (function_exists("query_in_combat", avatar)) {
    if (avatar->query_in_combat()) {
      avatar_experience(avatar, "You are already in combat.\n");

      return 1;
    }
  }

  if (!stringp(arg))
    arg = "";

  normalized = lower_case(trim(arg));

  if (normalized == "") {
    avatar_experience(avatar, "Attack what?\n");

    return 1;
  }

  target = resolve_environment_target(avatar, normalized);

  if (!objectp(target)) {
    avatar_experience(avatar, "You do not see that target here.\n");

    return 1;
  }

  if (!function_exists("is_npc", target) || !target->is_npc()) {
    avatar_experience(avatar, "You can only attack hostile creatures.\n");

    return 1;
  }

  if (function_exists("query_in_combat", target)) {
    if (target->query_in_combat()) {
      avatar_experience(avatar, target->name() + " is already in combat.\n");

      return 1;
    }
  }

  if (!COMBAT_D->start_fight(avatar, target)) {
    avatar_experience(avatar, "You fail to engage in combat.\n");

    return 1;
  }

  return 1;
}
