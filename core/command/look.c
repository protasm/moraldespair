/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/look.c.
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
    "Usage: look or look <target>\n"
    "Show the description of your current location.\n"
    "You can also look at a specific target to inspect it.\n"
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
  object env;
  object link;
  object target_object;
  mapping exits;
  mapping direction_aliases;
  string target;
  string target_short;
  string description;
  int target_is_npc;
  int used_long_description;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = lower_case(trim(arg));

  if (target != "") {
    direction_aliases = ([
      "n" : "north",
      "s" : "south",
      "e" : "east",
      "w" : "west",
      "ne" : "northeast",
      "nw" : "northwest",
      "se" : "southeast",
      "sw" : "southwest",
      "u" : "up",
      "d" : "down"
    ]);

    if (mapp(direction_aliases) && stringp(direction_aliases[target]))
      target = direction_aliases[target];

    env = environment(avatar);

    if (objectp(env)) {
      exits = LINK_D->links_by_direction_for_room(base_name(env));

      if (mapp(exits) && objectp(exits[target]))
        link = exits[target];

      if (objectp(link)) {
        if (function_exists("describe_from_endpoint", link))
          description = link->describe_from_endpoint(base_name(env));
        else if (function_exists("appearance", link))
          description = link->appearance(base_name(env));

        if (!stringp(description) || description == "")
          description = "It seems possible to go that way.\n";

        avatar_experience(avatar, description);

        return 1;
      }

      target_object = resolve_environment_target(avatar, target);

      if (objectp(target_object)) {
        target_is_npc = 0;
        description = "";
        target_short = "";
        used_long_description = 0;

        if (function_exists("is_npc", target_object))
          target_is_npc = target_object->is_npc();

        if (!intp(target_is_npc))
          target_is_npc = 0;

        if (function_exists("long", target_object)) {
          description = target_object->long();

          if (stringp(description) && description != "")
            used_long_description = 1;
        }

        if (!stringp(description) || description == "") {
          if (function_exists("short", target_object))
            description = target_object->short();
        }

        if (target_is_npc && used_long_description) {
          if (function_exists("short", target_object))
            target_short = target_object->short();

          if (stringp(target_short) && target_short != "")
            description = target_short + "\n" + description;
        }

        if (!stringp(description) || description == "")
          description = "You don't see anything unusual.\n";

        if (description[<1] != '\n')
          description += "\n";

        avatar_experience(avatar, description);

        return 1;
      }
    }

    avatar_experience(avatar, "You don't see that here.\n");

    return 1;
  }

  if (function_exists("show_location", avatar)) {
    avatar->show_location(1, 1);

    return 1;
  }

  avatar_experience(avatar, "You are nowhere.\n");

  return 1;
}
