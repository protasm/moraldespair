/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/npc/npc.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include <globals.h>
 *   - #include "/core/mfun/level.c"
 */

inherit "/core/object/object";

#include "npc.h"
#include <globals.h>
#include "/core/mfun/level.c"

string npc_name;
string npc_short;
string npc_long;
string *npc_ids;
int npc_level;
int npc_mobility_enabled;
int npc_mobility_min_delay;
int npc_mobility_max_delay;
int npc_mobility_move_chance;
int npc_path_memory_max;
string npc_spawn_anchor;
string *npc_path_memory;
string *npc_fidget_texts;
string npc_sensory_form;
mapping npc_sensor_profile_override;

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Initializes default identity fields for a non-player avatar.
 * Side effects:
 *   Stores baseline NPC metadata in object state.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  npc_name = "Unknown";
  npc_short = "Unknown";
  npc_long = "";
  npc_ids = ({ "unknown" });
  npc_level = 1;
  npc_mobility_enabled = 0;
  npc_mobility_min_delay = 50;
  npc_mobility_max_delay = 70;
  npc_mobility_move_chance = 50;
  npc_path_memory_max = 0;
  npc_spawn_anchor = "";
  npc_path_memory = ({ });
  npc_fidget_texts = ({ });
  npc_sensory_form = "humanoid";
  npc_sensor_profile_override = 0;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles sensory_form for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns normalized form identity for sensory resolution.
 * Side effects:
 *   None.
 * Returns:
 *   string result from sensory_form.
 */
string sensory_form() {
  if (!stringp(npc_sensory_form) || npc_sensory_form == "")
    return "humanoid";

  return npc_sensory_form;
}

/* Method Summary:
 * Purpose:
 *   Handles set_sensory_form for this object.
 * Parameters:
 *   - string new_form
 * Approach:
 *   Stores normalized form identity for this NPC's sensors.
 * Side effects:
 *   Mutates NPC sensory form metadata.
 * Returns:
 *   int result from set_sensory_form.
 */
int set_sensory_form(string new_form) {
  string normalized;

  if (!stringp(new_form))
    return 0;

  normalized = lower_case(trim(new_form));

  if (normalized == "")
    return 0;

  if (!EXPERIENCE_D->is_valid_form(normalized))
    return 0;

  npc_sensory_form = normalized;

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles sensory_profile for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns optional per-NPC sensor override mapping.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from sensory_profile.
 */
mapping sensory_profile() {
  if (!mapp(npc_sensor_profile_override))
    return 0;

  return copy(npc_sensor_profile_override);
}

/* Method Summary:
 * Purpose:
 *   Handles set_sensory_profile for this object.
 * Parameters:
 *   - mapping profile_override
 * Approach:
 *   Stores runtime sensor overrides for dynamic NPC behavior.
 * Side effects:
 *   Mutates NPC sensory override state.
 * Returns:
 *   void result from set_sensory_profile.
 */
void set_sensory_profile(mapping profile_override) {
  if (!mapp(profile_override)) {
    npc_sensor_profile_override = 0;

    return;
  }

  npc_sensor_profile_override = copy(profile_override);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_path_memory_max for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns configured stack cap where 0 means unbounded memory.
 * Side effects:
 *   None.
 * Returns:
 *   int result from query_path_memory_max.
 */
int query_path_memory_max() {
  if (!intp(npc_path_memory_max) || npc_path_memory_max < 0)
    npc_path_memory_max = 0;

  return npc_path_memory_max;
}

/* Method Summary:
 * Purpose:
 *   Handles set_path_memory_max for this object.
 * Parameters:
 *   - int max_entries
 * Approach:
 *   Stores bounded path stack size and trims existing memory to fit.
 * Side effects:
 *   Mutates NPC path memory sizing and may drop oldest non-root paths.
 * Returns:
 *   void result from set_path_memory_max.
 */
void set_path_memory_max(int max_entries) {
  if (!intp(max_entries))
    return;

  if (max_entries < 0)
    max_entries = 0;

  npc_path_memory_max = max_entries;

  if (!pointerp(npc_path_memory))
    npc_path_memory = ({ });

  if (npc_path_memory_max < 1)
    return;

  while (sizeof(npc_path_memory) > npc_path_memory_max) {
    if (sizeof(npc_path_memory) < 2)
      npc_path_memory = npc_path_memory[0..npc_path_memory_max - 1];
    else
      npc_path_memory = ({ npc_path_memory[0] }) + npc_path_memory[2..];
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_path_memory for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns a defensive copy of remembered room paths.
 * Side effects:
 *   None.
 * Returns:
 *   string *result from query_path_memory.
 */
string *query_path_memory() {
  if (!pointerp(npc_path_memory))
    npc_path_memory = ({ });

  return copy(npc_path_memory);
}

/* Method Summary:
 * Purpose:
 *   Handles push_path_memory for this object.
 * Parameters:
 *   - string room_path
 * Approach:
 *   Pushes a normalized room path onto the memory stack.
 * Side effects:
 *   Mutates NPC path memory state.
 * Returns:
 *   void result from push_path_memory.
 */
void push_path_memory(string room_path) {
  string normalized;

  if (!stringp(room_path))
    return;

  normalized = trim(room_path);

  if (normalized == "")
    return;

  if (!pointerp(npc_path_memory))
    npc_path_memory = ({ });

  npc_path_memory += ({ normalized });

  if (query_path_memory_max() > 0) {
    while (sizeof(npc_path_memory) > query_path_memory_max()) {
      if (sizeof(npc_path_memory) < 2)
        npc_path_memory = npc_path_memory[0..query_path_memory_max() - 1];
      else
        npc_path_memory = ({ npc_path_memory[0] }) + npc_path_memory[2..];
    }
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles pop_path_memory_to for this object.
 * Parameters:
 *   - string room_path
 * Approach:
 *   Pops remembered paths until the target room becomes stack top.
 * Side effects:
 *   Mutates NPC path memory state.
 * Returns:
 *   int result from pop_path_memory_to.
 */
int pop_path_memory_to(string room_path) {
  int index;

  if (!stringp(room_path))
    return 0;

  if (!pointerp(npc_path_memory))
    npc_path_memory = ({ });

  index = member_array(room_path, npc_path_memory);

  if (index == -1)
    return 0;

  npc_path_memory = npc_path_memory[0..index];

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles move for this object.
 * Parameters:
 *   - mixed dest
 * Approach:
 *   Moves the NPC and updates stack-based room path memory.
 * Side effects:
 *   May move this NPC and mutates remembered route history.
 * Returns:
 *   int result from move.
 */
int move(mixed dest) {
  object origin;
  object destination;
  string destination_path;
  int moved;
  int popped;

  origin = environment(this_object());
  moved = ::move(dest);

  if (!moved)
    return moved;

  destination = environment(this_object());

  if (!objectp(destination))
    return moved;

  if (objectp(origin) && destination == origin)
    return moved;

  destination_path = "";

  if (function_exists("link_endpoint_id", destination))
    destination_path = destination->link_endpoint_id();

  if (!stringp(destination_path) || destination_path == "")
    destination_path = base_name(destination);

  if (!stringp(destination_path) || destination_path == "")
    return moved;

  if (!pointerp(npc_path_memory))
    npc_path_memory = ({ });

  if (!sizeof(npc_path_memory)) {
    push_path_memory(destination_path);

    return moved;
  }

  popped = pop_path_memory_to(destination_path);

  if (!popped)
    push_path_memory(destination_path);

  return moved;
}

/* Method Summary:
 * Purpose:
 *   Handles remove for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Clears scheduled mobility work before object destruction.
 * Side effects:
 *   Cancels pending call_out state and destructs the NPC.
 * Returns:
 *   void result from remove.
 */
void remove() {
  remove_call_out("mobility_tick");
  ::remove();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles heart_beat for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Keeps heartbeat behavior explicit for future NPC controllers.
 * Side effects:
 *   None.
 * Returns:
 *   void result from heart_beat.
 */
void heart_beat() {
  ::heart_beat();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles is_living for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Identifies NPCs as living world entities.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_living.
 */
int is_living() {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles is_npc for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Provides explicit NPC type detection for room and command logic.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_npc.
 */
int is_npc() {
  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles query_spawn_anchor for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns persistent room anchor identifier for idempotent spawns.
 * Side effects:
 *   None.
 * Returns:
 *   string result from query_spawn_anchor.
 */
string query_spawn_anchor() {
  if (!stringp(npc_spawn_anchor))
    return "";

  return npc_spawn_anchor;
}

/* Method Summary:
 * Purpose:
 *   Handles set_spawn_anchor for this object.
 * Parameters:
 *   - string anchor_id
 * Approach:
 *   Stores normalized room anchor id used by spawn reconciliation logic.
 * Side effects:
 *   Mutates NPC spawn metadata.
 * Returns:
 *   void result from set_spawn_anchor.
 */
void set_spawn_anchor(string anchor_id) {
  if (!stringp(anchor_id)) {
    npc_spawn_anchor = "";

    return;
  }

  npc_spawn_anchor = trim(anchor_id);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_level for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns numeric NPC level with defensive fallback.
 * Side effects:
 *   None.
 * Returns:
 *   int result from query_level.
 */
int query_level() {
  npc_level = normalize_level_value(npc_level);

  return npc_level;
}

/* Method Summary:
 * Purpose:
 *   Handles set_level for this object.
 * Parameters:
 *   - int new_level
 * Approach:
 *   Stores NPC level while enforcing a minimum of 1.
 * Side effects:
 *   Mutates NPC progression metadata.
 * Returns:
 *   void result from set_level.
 */
void set_level(int new_level) {
  npc_level = normalize_level_value(new_level);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles name for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns display name text for this NPC.
 * Side effects:
 *   None.
 * Returns:
 *   string result from name.
 */
string name() {
  if (!stringp(npc_name) || npc_name == "")
    return "Unknown";

  return npc_name;
}

/* Method Summary:
 * Purpose:
 *   Handles set_name for this object.
 * Parameters:
 *   - string new_name
 * Approach:
 *   Normalizes and stores display identity and a default id token.
 * Side effects:
 *   Mutates NPC identity state.
 * Returns:
 *   void result from set_name.
 */
void set_name(string new_name) {
  string normalized;
  string base_id;

  if (!stringp(new_name))
    return;

  normalized = trim(new_name);

  if (normalized == "")
    return;

  npc_name = normalized;
  base_id = lower_case(normalized);
  npc_ids = ({ base_id });

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles short for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns short description with name fallback.
 * Side effects:
 *   None.
 * Returns:
 *   string result from short.
 */
string short() {
  return short_for(this_player());
}

/* Method Summary:
 * Purpose:
 *   Handles short_for for this object.
 * Parameters:
 *   - object observer
 * Approach:
 *   Returns observer-aware short label with masked or visible level.
 * Side effects:
 *   None.
 * Returns:
 *   string result from short_for.
 */
string short_for(object observer) {
  string base_label;

  if (stringp(npc_short) && npc_short != "")
    base_label = npc_short;
  else
    base_label = name();

  return level_name_label_for_observer(base_label, query_level(), observer);
}

/* Method Summary:
 * Purpose:
 *   Handles set_short for this object.
 * Parameters:
 *   - string new_short
 * Approach:
 *   Stores short description text for room rendering.
 * Side effects:
 *   Mutates NPC descriptive state.
 * Returns:
 *   void result from set_short.
 */
void set_short(string new_short) {
  if (!stringp(new_short))
    return;

  npc_short = trim(new_short);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles long for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns long description for look-style inspection.
 * Side effects:
 *   None.
 * Returns:
 *   string result from long.
 */
string long() {
  if (!stringp(npc_long) || npc_long == "")
    return name() + " is here.\n";

  return npc_long;
}

/* Method Summary:
 * Purpose:
 *   Handles set_long for this object.
 * Parameters:
 *   - string new_long
 * Approach:
 *   Stores long description text for later inspection.
 * Side effects:
 *   Mutates NPC descriptive state.
 * Returns:
 *   void result from set_long.
 */
void set_long(string new_long) {
  if (!stringp(new_long))
    return;

  npc_long = trim(new_long);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles add_id for this object.
 * Parameters:
 *   - string new_id
 * Approach:
 *   Adds normalized lookup ids used by command targeting.
 * Side effects:
 *   Mutates id lookup state.
 * Returns:
 *   void result from add_id.
 */
void add_id(string new_id) {
  string normalized;

  if (!stringp(new_id))
    return;

  normalized = lower_case(trim(new_id));

  if (normalized == "")
    return;

  if (member_array(normalized, npc_ids) != -1)
    return;

  npc_ids += ({ normalized });

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles add_ids for this object.
 * Parameters:
 *   - string *new_ids
 * Approach:
 *   Applies add_id to each candidate id in the provided array.
 * Side effects:
 *   May mutate id lookup state.
 * Returns:
 *   void result from add_ids.
 */
void add_ids(string *new_ids) {
  int i;

  if (!pointerp(new_ids))
    return;

  for (i = 0; i < sizeof(new_ids); i++)
    add_id(new_ids[i]);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_mobility_enabled for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns whether periodic random movement is enabled.
 * Side effects:
 *   None.
 * Returns:
 *   int result from query_mobility_enabled.
 */
int query_mobility_enabled() {
  return npc_mobility_enabled;
}

/* Method Summary:
 * Purpose:
 *   Handles set_mobility_enabled for this object.
 * Parameters:
 *   - int enabled
 * Approach:
 *   Toggles autonomous room-to-room movement scheduling.
 * Side effects:
 *   Starts or cancels recurring movement call_out work.
 * Returns:
 *   void result from set_mobility_enabled.
 */
void set_mobility_enabled(int enabled) {
  if (!intp(enabled))
    return;

  if (enabled)
    npc_mobility_enabled = 1;
  else
    npc_mobility_enabled = 0;

  remove_call_out("mobility_tick");

  if (npc_mobility_enabled)
    schedule_mobility_tick();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_mobility_move_chance for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns percentage chance used for each movement tick.
 * Side effects:
 *   None.
 * Returns:
 *   int result from query_mobility_move_chance.
 */
int query_mobility_move_chance() {
  return npc_mobility_move_chance;
}

/* Method Summary:
 * Purpose:
 *   Handles set_mobility_move_chance for this object.
 * Parameters:
 *   - int percent
 * Approach:
 *   Clamps and stores per-tick movement chance as 0-100.
 * Side effects:
 *   Mutates movement behavior.
 * Returns:
 *   void result from set_mobility_move_chance.
 */
void set_mobility_move_chance(int percent) {
  if (!intp(percent))
    return;

  if (percent < 0)
    percent = 0;
  else if (percent > 100)
    percent = 100;

  npc_mobility_move_chance = percent;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles set_mobility_delay_range for this object.
 * Parameters:
 *   - int min_seconds, int max_seconds
 * Approach:
 *   Stores bounded movement timer settings and refreshes scheduling.
 * Side effects:
 *   Mutates movement timing and may reschedule mobility call_out.
 * Returns:
 *   void result from set_mobility_delay_range.
 */
void set_mobility_delay_range(int min_seconds, int max_seconds) {
  int temp;

  if (!intp(min_seconds) || !intp(max_seconds))
    return;

  if (min_seconds < 1)
    min_seconds = 1;

  if (max_seconds < 1)
    max_seconds = 1;

  if (max_seconds < min_seconds) {
    temp = min_seconds;
    min_seconds = max_seconds;
    max_seconds = temp;
  }

  npc_mobility_min_delay = min_seconds;
  npc_mobility_max_delay = max_seconds;

  if (npc_mobility_enabled) {
    remove_call_out("mobility_tick");
    schedule_mobility_tick();
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles schedule_mobility_tick for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Computes a randomized delay and schedules the next mobility tick.
 * Side effects:
 *   Adds a call_out for future movement behavior.
 * Returns:
 *   void result from schedule_mobility_tick.
 */
void schedule_mobility_tick() {
  int delay;
  int range;

  if (!npc_mobility_enabled)
    return;

  if (npc_mobility_min_delay < 1)
    npc_mobility_min_delay = 1;

  if (npc_mobility_max_delay < npc_mobility_min_delay)
    npc_mobility_max_delay = npc_mobility_min_delay;

  delay = npc_mobility_min_delay;
  range = npc_mobility_max_delay - npc_mobility_min_delay;

  if (range > 0)
    delay += random(range + 1);

  call_out("mobility_tick", delay);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles mobility_tick for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Performs one move-or-stay decision and schedules the next tick.
 * Side effects:
 *   May move this NPC to a neighboring room.
 * Returns:
 *   void result from mobility_tick.
 */
void mobility_tick() {
  int moved;

  if (!npc_mobility_enabled)
    return;

  moved = attempt_random_move();

  if (!moved)
    emit_fidget();

  schedule_mobility_tick();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles attempt_random_move for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Randomly decides whether to move, then traverses a random valid link.
 * Side effects:
 *   May move this NPC to a linked room.
 * Returns:
 *   int result from attempt_random_move.
 */
int attempt_random_move() {
  object env;
  object destination;
  object link_daemon;
  object *links;
  object selected_link;
  string endpoint_id;

  env = environment(this_object());

  if (!objectp(env))
    return 0;

  if (npc_mobility_move_chance < 1)
    return 0;

  if (npc_mobility_move_chance < 100) {
    if (random(100) >= npc_mobility_move_chance)
      return 0;
  }

  endpoint_id = "";

  if (function_exists("link_endpoint_id", env))
    endpoint_id = env->link_endpoint_id();

  if (!stringp(endpoint_id) || endpoint_id == "")
    endpoint_id = base_name(env);

  if (!stringp(endpoint_id) || endpoint_id == "")
    return 0;

  link_daemon = find_object("/core/daemon/link_d");

  if (!objectp(link_daemon))
    link_daemon = load_object("/core/daemon/link_d");

  if (!objectp(link_daemon))
    return 0;

  if (!function_exists("links_for_room", link_daemon))
    return 0;

  links = link_daemon->links_for_room(endpoint_id);

  if (!pointerp(links) || !sizeof(links))
    return 0;

  selected_link = links[random(sizeof(links))];

  if (!objectp(selected_link))
    return 0;

  if (!function_exists("traverse", selected_link))
    return 0;

  selected_link->traverse(this_object(), env);
  destination = environment(this_object());

  if (objectp(destination) && destination != env) {
    MOVE_D->announce_transition(this_object(), env, destination, selected_link, "");

    return 1;
  }

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles set_fidget_text for this object.
 * Parameters:
 *   - string text
 * Approach:
 *   Sets one fallback fidget line used when mobility ticks do not move.
 * Side effects:
 *   Replaces configured fidget line list.
 * Returns:
 *   void result from set_fidget_text.
 */
void set_fidget_text(string text) {
  string normalized;

  if (!stringp(text))
    return;

  normalized = trim(text);

  if (normalized == "") {
    npc_fidget_texts = ({ });

    return;
  }

  if (normalized[<1] != '\n')
    normalized += "\n";

  npc_fidget_texts = ({ normalized });

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles set_fidget_texts for this object.
 * Parameters:
 *   - string *texts
 * Approach:
 *   Stores one or more normalized fidget lines for idle mobility ticks.
 * Side effects:
 *   Replaces configured fidget line list.
 * Returns:
 *   void result from set_fidget_texts.
 */
void set_fidget_texts(string *texts) {
  string *normalized;
  string line;
  int i;

  if (!pointerp(texts)) {
    npc_fidget_texts = ({ });

    return;
  }

  normalized = ({ });

  for (i = 0; i < sizeof(texts); i++) {
    line = texts[i];

    if (!stringp(line))
      continue;

    line = trim(line);

    if (line == "")
      continue;

    if (line[<1] != '\n')
      line += "\n";

    normalized += ({ line });
  }

  npc_fidget_texts = normalized;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_fidget for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Emits one random fidget line to connected avatars in the same room.
 * Side effects:
 *   Sends experience text to nearby players.
 * Returns:
 *   void result from emit_fidget.
 */
void emit_fidget() {
  object env;
  string line;

  if (!pointerp(npc_fidget_texts) || !sizeof(npc_fidget_texts))
    return;

  env = environment(this_object());

  if (!objectp(env))
    return;

  line = npc_fidget_texts[random(sizeof(npc_fidget_texts))];

  if (!stringp(line) || line == "")
    return;

  EXPERIENCE_D->emit_environment_ambience(
    this_object(),
    env,
    "environment.fidget",
    line,
    "audio"
  );

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles id for this object.
 * Parameters:
 *   - string an_id
 * Approach:
 *   Matches target ids against normalized identity tokens.
 * Side effects:
 *   None.
 * Returns:
 *   int result from id.
 */
int id(string an_id) {
  string normalized;

  if (!stringp(an_id))
    return 0;

  normalized = lower_case(trim(an_id));

  if (normalized == "")
    return 0;

  if (!pointerp(npc_ids))
    return 0;

  if (member_array(normalized, npc_ids) == -1)
    return 0;

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles experience for this object.
 * Parameters:
 *   - mapping event
 * Approach:
 *   Defines event ingress for future AI/controller handling.
 * Side effects:
 *   None.
 * Returns:
 *   void result from experience.
 */
void experience(mapping event) {
  if (!mapp(event))
    return;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles catch_tell for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Accepts ambient text without forcing output behavior.
 * Side effects:
 *   None.
 * Returns:
 *   void result from catch_tell.
 */
void catch_tell(string message) {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles net_dead for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Stub for interface compatibility with avatar-like objects.
 * Side effects:
 *   None.
 * Returns:
 *   void result from net_dead.
 */
void net_dead() {
  return;
}

/* Method Summary:
 * Purpose:
 *   Handles move_or_destruct for this object.
 * Parameters:
 *   - object dest
 * Approach:
 *   Keeps object alive by moving to destination when valid.
 * Side effects:
 *   May move this NPC between rooms.
 * Returns:
 *   void result from move_or_destruct.
 */
void move_or_destruct(object dest) {
  if (!objectp(dest))
    return;

  move(dest);

  return;
}
