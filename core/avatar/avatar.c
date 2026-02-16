/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/avatar/avatar.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include "avatar-data.c"
 *   - #include "avatar-process-input.c"
 */

inherit "/core/object/object";

#include "avatar.h"
#include "avatar-data.c"
#include "avatar-process-input.c"

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

  enable_commands();
  set_heart_beat(1);

  if (is_wizard()) {
    experience_text("Enabling wizard privileges...");

    enable_wizard();

    experience_text(" done!\n");
  }
}

/* Method Summary:
 * Purpose:
 *   Handles heart_beat for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for heart_beat.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from heart_beat.
 */
void heart_beat() {
  ::heart_beat();
}

/* Method Summary:
 * Purpose:
 *   Handles is_living for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for is_living.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_living.
 */
int is_living() {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles check_wizard for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for check_wizard.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from check_wizard.
 */
void check_wizard() {
  int has_wizard_access;

  has_wizard_access = is_wizard();

  if (has_wizard_access) {
    experience_text("Enabling wizard commands...");

    enable_wizard();

    experience_text(" done!\n");
  }
}

/* Method Summary:
 * Purpose:
 *   Handles experience for this object.
 * Parameters:
 *   - mapping event
 * Approach:
 *   Central ingress for avatar experience before delivery to controllers.
 * Side effects:
 *   May write text to the controlling player object.
 * Returns:
 *   void result from experience.
 */
void experience(mapping event) {
  object controller;
  string text;

  if (!mapp(event))
    return;

  text = event["text"];

  if (!stringp(text) || text == "")
    return;

  controller = player();

  if (objectp(controller) && function_exists("deliver_experience", controller)) {
    controller->deliver_experience(event);

    return;
  }

  if (userp(this_object()))
    tell_object(this_object(), text);
}

/* Method Summary:
 * Purpose:
 *   Handles experience_text for this object.
 * Parameters:
 *   - string text
 * Approach:
 *   Convenience wrapper for text-only experience payloads.
 * Side effects:
 *   May write text to the controlling player object.
 * Returns:
 *   void result from experience_text.
 */
void experience_text(string text) {
  mapping event;

  if (!stringp(text))
    return;

  event = ([
    "type" : "text",
    "text" : text
  ]);
  experience(event);
}

/* Method Summary:
 * Purpose:
 *   Handles endpoint_id_for_room for this object.
 * Parameters:
 *   - object room
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_id_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_id_for_room.
 */
string endpoint_id_for_room(object room) {
  string endpoint_id;

  endpoint_id = "";

  if (!objectp(room))
    return endpoint_id;

  if (function_exists("link_endpoint_id", room))
    endpoint_id = room->link_endpoint_id();

  if (!stringp(endpoint_id) || endpoint_id == "")
    endpoint_id = base_name(room);

  return endpoint_id;
}

/* Method Summary:
 * Purpose:
 *   Handles abbreviate_exit for this object.
 * Parameters:
 *   - string direction
 * Approach:
 *   Validates inputs and executes explicit local logic for abbreviate_exit.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from abbreviate_exit.
 */
string abbreviate_exit(string direction) {
  mapping abbreviations;
  string abbreviated;

  abbreviations = ([
    "north" : "n",
    "south" : "s",
    "east" : "e",
    "west" : "w",
    "northeast" : "ne",
    "northwest" : "nw",
    "southeast" : "se",
    "southwest" : "sw",
    "up" : "u",
    "down" : "d"
  ]);

  abbreviated = abbreviations[direction];

  if (stringp(abbreviated))
    return abbreviated;

  return direction;
}

/* Method Summary:
 * Purpose:
 *   Handles show_room_occupants for this object.
 * Parameters:
 *   - object env, object observer, int separate_from_exits
 * Approach:
 *   Validates inputs and executes explicit local logic for show_room_occupants.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from show_room_occupants.
 */
int show_room_occupants(object env, object observer, int separate_from_exits) {
  object *contents;
  object occupant;
  string occupant_short;
  string *player_names;
  string *npc_names;
  int j;
  int show_occupant;
  int npc_state;

  if (!objectp(env))
    return 0;

  contents = all_inventory(env);
  player_names = ({ });
  npc_names = ({ });

  if (pointerp(contents) && sizeof(contents)) {
    for (j = 0; j < sizeof(contents); j++) {
      occupant = contents[j];

      if (!objectp(occupant) || occupant == this_object())
        continue;

      show_occupant = 0;
      npc_state = 0;

      if (is_connected_avatar(occupant))
        show_occupant = 1;
      else if (function_exists("is_npc", occupant)) {
        npc_state = occupant->is_npc();

        if (intp(npc_state) && npc_state)
          show_occupant = 1;
      }

      if (!show_occupant)
        continue;

      occupant_short = "";

      if (function_exists("short_for", occupant))
        occupant_short = occupant->short_for(observer);

      if (!stringp(occupant_short) || occupant_short == "")
        if (function_exists("short", occupant))
          occupant_short = occupant->short();

      if (!stringp(occupant_short) || occupant_short == "") {
        if (function_exists("name", occupant))
          occupant_short = occupant->name();
      }

      if (!stringp(occupant_short) || occupant_short == "")
        continue;

      if (is_connected_avatar(occupant))
        player_names += ({ occupant_short });
      else
        npc_names += ({ occupant_short });
    }
  }

  if (sizeof(player_names)) {
    if (separate_from_exits)
      experience_text("\n");

    player_names = sort_array(player_names, 1);
    experience_text("Also here: " + implode(player_names, ", ") + "\n");
    separate_from_exits = 0;
  }

  if (sizeof(npc_names)) {
    if (separate_from_exits)
      experience_text("\n");

    npc_names = sort_array(npc_names, 1);

    if (sizeof(player_names))
      experience_text("\n");

    for (j = 0; j < sizeof(npc_names); j++)
      experience_text(npc_names[j] + "\n");
  }

  if (sizeof(player_names) || sizeof(npc_names))
    return 1;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles show_location for this object.
 * Parameters:
 *   - int force_verbose, int show_path
 * Approach:
 *   Validates inputs and executes explicit local logic for show_location.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from show_location.
 */
void show_location(int force_verbose, int show_path) {
  object env;
  string short_desc, long_desc, room_path, room_endpoint_id;
  mapping exits;
  string *dirs, *abbr_dirs;
  int brief_state, i;
  int show_wizard_path;
  int has_wizard_access;

  env = environment(this_object());

  if (!objectp(env)) {
    experience_text("You are nowhere.\n");

    return;
  }

  if (!force_verbose)
    brief_state = brief();

  room_endpoint_id = endpoint_id_for_room(env);

  if (brief_state) {
    short_desc = env->short();

    if (stringp(short_desc) && short_desc != "")
      experience_text(short_desc + "\n");

    exits = LINK_D->links_by_direction_for_room(room_endpoint_id);

    if (mapp(exits) && sizeof(exits)) {
      dirs = sort_array(keys(exits), 1);
      abbr_dirs = ({});

      for (i = 0; i < sizeof(dirs); i++)
        abbr_dirs += ({ abbreviate_exit(dirs[i]) });

      experience_text("[Exits: " + implode(abbr_dirs, " ") + "]\n");
    } else
      experience_text("[Exits: none]\n");

    show_room_occupants(env, this_object(), 1);

    return;
  }

  short_desc = env->short();
  room_path = room_endpoint_id;
  show_wizard_path = 0;
  has_wizard_access = 0;

  if (wizardp(this_object()))
    has_wizard_access = 1;
  else if (function_exists("is_wizard", this_object()))
    has_wizard_access = is_wizard();

  if (show_path && has_wizard_access &&
    stringp(short_desc) && short_desc != "" &&
    stringp(room_path) && room_path != "")
    show_wizard_path = 1;

  if (stringp(short_desc) && short_desc != "") {
    if (show_wizard_path)
      experience_text("\n");

    experience_text(short_desc + "\n");
  }

  if (show_wizard_path)
    experience_text("(" + room_path + ")\n");

  experience_text(DISPLAY_DIVIDER + "\n");

  long_desc = env->long();

  if (stringp(long_desc) && long_desc != "") {
    experience_text(long_desc);

    if (long_desc[<1] != '\n')
      experience_text("\n");
  }

  experience_text("\n");
  show_room_occupants(env, this_object(), 0);
  experience_text("\n");

  exits = LINK_D->links_by_direction_for_room(room_endpoint_id);

  if (mapp(exits) && sizeof(exits)) {
    dirs = sort_array(keys(exits), 1);

    experience_text("Exits: " + implode(dirs, ", ") + "\n");
  } else {
    experience_text("Exits: none\n");
  }
}

/* Method Summary:
 * Purpose:
 *   Handles catch_tell for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for catch_tell.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from catch_tell.
 */
void catch_tell(string message) {
  experience_text(message);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles gmcp for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for gmcp.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from gmcp.
 */
void gmcp(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles gmcp_enable for this object.
 * Parameters:
 *   - int enabled
 * Approach:
 *   Validates inputs and executes explicit local logic for gmcp_enable.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from gmcp_enable.
 */
void gmcp_enable(int enabled) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles logon for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for logon.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from logon.
 */
void logon() {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles msdp for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for msdp.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from msdp.
 */
void msdp(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles msdp_enable for this object.
 * Parameters:
 *   - int enabled
 * Approach:
 *   Validates inputs and executes explicit local logic for msdp_enable.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from msdp_enable.
 */
void msdp_enable(int enabled) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles msp_enable for this object.
 * Parameters:
 *   - int enabled
 * Approach:
 *   Validates inputs and executes explicit local logic for msp_enable.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from msp_enable.
 */
void msp_enable(int enabled) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles mxp_enable for this object.
 * Parameters:
 *   - int enabled
 * Approach:
 *   Validates inputs and executes explicit local logic for mxp_enable.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from mxp_enable.
 */
void mxp_enable(int enabled) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles mxp_tag for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for mxp_tag.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from mxp_tag.
 */
void mxp_tag(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles net_dead for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for net_dead.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from net_dead.
 */
void net_dead() {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles receive_ed for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for receive_ed.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from receive_ed.
 */
void receive_ed(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles receive_environ for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for receive_environ.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from receive_environ.
 */
void receive_environ(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles receive_snoop for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for receive_snoop.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from receive_snoop.
 */
void receive_snoop(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles telnet_suboption for this object.
 * Parameters:
 *   - int option, string message
 * Approach:
 *   Validates inputs and executes explicit local logic for telnet_suboption.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from telnet_suboption.
 */
void telnet_suboption(int option, string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles terminal_colour_replace for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for terminal_colour_replace.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from terminal_colour_replace.
 */
void terminal_colour_replace(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles terminal_type for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for terminal_type.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from terminal_type.
 */
void terminal_type(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles window_size for this object.
 * Parameters:
 *   - int width, int height
 * Approach:
 *   Validates inputs and executes explicit local logic for window_size.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from window_size.
 */
void window_size(int width, int height) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles write_prompt for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for write_prompt.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from write_prompt.
 */
void write_prompt() {
  experience_text(PLAYER_PROMPT);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles zmp for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for zmp.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from zmp.
 */
void zmp(string message) {
  return;
}
