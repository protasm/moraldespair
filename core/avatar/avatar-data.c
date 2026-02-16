/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/avatar/avatar-data.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include <globals.h>
 *   - #include "/core/mfun/level.c"
 */

#include <globals.h>
#include "/core/mfun/level.c"

string player_name;
object player_object, account_object;
string avatar_sensory_form;
mapping avatar_sensor_profile_override;
mapping avatar_soul_emotes;
string avatar_soul_emotes_file;
int ensure_player_level(mapping player_data);
int query_level();
int save_player_data(mapping player_data);
string short_for(object observer);

/* Method Summary:
 * Purpose:
 *   Handles normalize_key for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_key.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_key.
 */
string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

/* Method Summary:
 * Purpose:
 *   Handles soul_emotes_path for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns a stable filesystem path for the basic soul emote catalog.
 * Side effects:
 *   None.
 * Returns:
 *   string result from soul_emotes_path.
 */
string soul_emotes_path() {
  if (!stringp(avatar_soul_emotes_file) || avatar_soul_emotes_file == "")
    avatar_soul_emotes_file = "/core/avatar/soul/basic-emotes.json";

  return avatar_soul_emotes_file;
}

/* Method Summary:
 * Purpose:
 *   Handles read_json_file for this object.
 * Parameters:
 *   - string file
 * Approach:
 *   Reads a JSON file in fixed-size line chunks to avoid short read
 *   truncation and returns the full text body.
 * Side effects:
 *   None.
 * Returns:
 *   string result from read_json_file.
 */
string read_json_file(string file) {
  string chunk, contents;
  string *chunks;
  int line, line_count;

  if (!stringp(file) || file == "")
    return 0;

  chunks = ({ });
  line = 1;
  line_count = 500;

  while (1) {
    chunk = read_file(file, line, line_count);

    if (!stringp(chunk))
      break;

    chunks += ({ chunk });
    line += line_count;
  }

  if (!sizeof(chunks))
    return 0;

  contents = implode(chunks, "");

  if (!stringp(contents) || contents == "")
    return 0;

  return contents;
}

/* Method Summary:
 * Purpose:
 *   Handles parse_json for this object.
 * Parameters:
 *   - string raw
 * Approach:
 *   Decodes JSON via /std/json and returns the parsed LPC value.
 * Side effects:
 *   None.
 * Returns:
 *   mixed result from parse_json.
 */
mixed parse_json(string raw) {
  object parser;

  if (!stringp(raw) || raw == "")
    return 0;

  parser = find_object("/std/json");

  if (!objectp(parser))
    parser = load_object("/std/json");

  if (!objectp(parser))
    return 0;

  return parser->json_decode(raw);
}

/* Method Summary:
 * Purpose:
 *   Handles soul_emotes for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Lazily loads emote definitions from JSON and caches them in-memory.
 * Side effects:
 *   Mutates in-memory soul emote cache.
 * Returns:
 *   mapping result from soul_emotes.
 */
mapping soul_emotes() {
  mixed parsed;
  string file, raw;

  if (mapp(avatar_soul_emotes))
    return avatar_soul_emotes;

  file = soul_emotes_path();
  raw = read_json_file(file);

  if (!stringp(raw))
    return ([]);

  parsed = parse_json(raw);

  if (!mapp(parsed))
    return ([]);

  avatar_soul_emotes = parsed;

  return avatar_soul_emotes;
}

/* Method Summary:
 * Purpose:
 *   Handles soul_emote for this object.
 * Parameters:
 *   - string verb
 * Approach:
 *   Retrieves a single emote definition by normalized command verb.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from soul_emote.
 */
mapping soul_emote(string verb) {
  mapping emotes;
  string normalized;
  mixed definition;

  normalized = normalize_key(verb);

  if (normalized == "")
    return 0;

  emotes = soul_emotes();

  if (!mapp(emotes))
    return 0;

  definition = emotes[normalized];

  if (!mapp(definition))
    return 0;

  return definition;
}

/* Method Summary:
 * Purpose:
 *   Handles player_file_path for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for player_file_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from player_file_path.
 */
string player_file_path() {
  string username, player;

  if (!objectp(account_object))
    return "";

  username = account_object->username();
  player = normalize_key(player_name);

  if (username == "" || player == "")
    return "";

  return "/a/" + username + "/" + player + ".o";
}

/* Method Summary:
 * Purpose:
 *   Handles load_player_data for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for load_player_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from load_player_data.
 */
mapping load_player_data() {
  mapping player_data;
  string path, raw;
  int changed;

  path = player_file_path();

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  player_data = restore_variable(raw);

  if (!mapp(player_data))
    return 0;

  changed = ensure_player_level(player_data);

  if (changed)
    save_player_data(player_data);

  return player_data;
}

/* Method Summary:
 * Purpose:
 *   Handles save_player_data for this object.
 * Parameters:
 *   - mapping player_data
 * Approach:
 *   Validates inputs and executes explicit local logic for save_player_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from save_player_data.
 */
int save_player_data(mapping player_data) {
  string path, raw;

  if (!mapp(player_data))
    return 0;

  path = player_file_path();

  if (path == "")
    return 0;

  raw = save_variable(player_data);

  rm(path);

  return write_file(path, raw);
}

/* Method Summary:
 * Purpose:
 *   Handles ensure_player_level for this object.
 * Parameters:
 *   - mapping player_data
 * Approach:
 *   Ensures avatar save data contains a normalized numeric level.
 * Side effects:
 *   May mutate provided player_data mapping.
 * Returns:
 *   int result from ensure_player_level.
 */
int ensure_player_level(mapping player_data) {
  int current_level;
  int normalized_level;

  if (!mapp(player_data))
    return 0;

  current_level = player_data["level"];
  normalized_level = normalize_level_value(current_level);

  if (!intp(current_level) || current_level != normalized_level) {
    player_data["level"] = normalized_level;

    return 1;
  }

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles player for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for player.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from player.
 */
object player() {
  return player_object;
}

/* Method Summary:
 * Purpose:
 *   Handles set_player for this object.
 * Parameters:
 *   - object player
 * Approach:
 *   Validates inputs and executes explicit local logic for set_player.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_player.
 */
void set_player(object player) {
  player_object = player;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles account for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for account.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from account.
 */
object account() {
  return account_object;
}

/* Method Summary:
 * Purpose:
 *   Handles set_account for this object.
 * Parameters:
 *   - object new_account
 * Approach:
 *   Validates inputs and executes explicit local logic for set_account.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
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
 *   Validates inputs and executes explicit local logic for name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from name.
 */
string name() {
  mapping player_data;
  string shown_name;

  shown_name = "";
  player_data = load_player_data();

  if (mapp(player_data))
    shown_name = player_data["display_name"];

  if (!stringp(shown_name) || shown_name == "")
    shown_name = player_name;

  if (!stringp(shown_name) || shown_name == "")
    return "";

  return capitalize(shown_name);
}

/* Method Summary:
 * Purpose:
 *   Handles set_name for this object.
 * Parameters:
 *   - string new_name
 * Approach:
 *   Validates inputs and executes explicit local logic for set_name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_name.
 */
void set_name(string new_name) {
  player_name = normalize_key(new_name);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles short for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns avatar display label in "Name (level)" format.
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
  return level_name_label_for_observer(name(), query_level(), observer);
}

/* Method Summary:
 * Purpose:
 *   Handles sensory_form for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Resolves saved form identity for sensory interpretation.
 * Side effects:
 *   None.
 * Returns:
 *   string result from sensory_form.
 */
string sensory_form() {
  mapping player_data;
  string saved_form;

  if (stringp(avatar_sensory_form) && avatar_sensory_form != "")
    return avatar_sensory_form;

  player_data = load_player_data();

  if (mapp(player_data))
    saved_form = normalize_key(player_data["sensory_form"]);

  if (!stringp(saved_form) || saved_form == "")
    saved_form = "humanoid";

  if (!EXPERIENCE_D->is_valid_form(saved_form))
    saved_form = "humanoid";

  avatar_sensory_form = saved_form;

  return avatar_sensory_form;
}

/* Method Summary:
 * Purpose:
 *   Handles set_sensory_form for this object.
 * Parameters:
 *   - string new_form
 * Approach:
 *   Stores and persists form identity used by sensory evaluation.
 * Side effects:
 *   Updates save data for the avatar.
 * Returns:
 *   int result from set_sensory_form.
 */
int set_sensory_form(string new_form) {
  mapping player_data;
  string normalized;

  normalized = normalize_key(new_form);

  if (normalized == "")
    return 0;

  if (!EXPERIENCE_D->is_valid_form(normalized))
    return 0;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["sensory_form"] = normalized;
  avatar_sensory_form = normalized;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles sensory_profile for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns optional per-avatar sensor override mapping.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from sensory_profile.
 */
mapping sensory_profile() {
  if (!mapp(avatar_sensor_profile_override))
    return 0;

  return copy(avatar_sensor_profile_override);
}

/* Method Summary:
 * Purpose:
 *   Handles set_sensory_profile for this object.
 * Parameters:
 *   - mapping profile_override
 * Approach:
 *   Stores runtime sensor overrides for testing and dynamic effects.
 * Side effects:
 *   Mutates runtime-only avatar sensory overrides.
 * Returns:
 *   void result from set_sensory_profile.
 */
void set_sensory_profile(mapping profile_override) {
  if (!mapp(profile_override)) {
    avatar_sensor_profile_override = 0;

    return;
  }

  avatar_sensor_profile_override = copy(profile_override);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles display_name for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for display_name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from display_name.
 */
string display_name() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return "";

  return player_data["display_name"];
}

/* Method Summary:
 * Purpose:
 *   Handles current_chapter for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for current_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from current_chapter.
 */
string current_chapter() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return "";

  if (!stringp(player_data["current_chapter"]))
    return "";

  return player_data["current_chapter"];
}

/* Method Summary:
 * Purpose:
 *   Handles set_current_chapter for this object.
 * Parameters:
 *   - string chapter_id
 * Approach:
 *   Validates inputs and executes explicit local logic for set_current_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_current_chapter.
 */
int set_current_chapter(string chapter_id) {
  mapping player_data;
  string normalized;

  normalized = normalize_key(chapter_id);

  if (normalized == "")
    return 0;

  if (!CHAPTER_D->chapter_exists(normalized))
    return 0;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["current_chapter"] = normalized;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles unlocked_chapters for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for unlocked_chapters.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from unlocked_chapters.
 */
string *unlocked_chapters() {
  mapping player_data;
  string *unlocked;

  player_data = load_player_data();

  if (!mapp(player_data))
    return ({});

  unlocked = player_data["unlocked_chapters"];

  if (!pointerp(unlocked))
    return ({});

  return unlocked;
}

/* Method Summary:
 * Purpose:
 *   Handles set_unlocked_chapters for this object.
 * Parameters:
 *   - string *chapter_ids
 * Approach:
 *   Validates inputs and executes explicit local logic for set_unlocked_chapters.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_unlocked_chapters.
 */
int set_unlocked_chapters(string *chapter_ids) {
  mapping player_data;
  string *normalized;
  string id;
  int i;

  if (!pointerp(chapter_ids))
    return 0;

  normalized = ({});

  for (i = 0; i < sizeof(chapter_ids); i++) {
    id = normalize_key(chapter_ids[i]);

    if (id == "")
      continue;

    if (!CHAPTER_D->chapter_exists(id))
      continue;

    if (member_array(id, normalized) == -1)
      normalized += ({ id });
  }

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["unlocked_chapters"] = normalized;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles unlock_chapter for this object.
 * Parameters:
 *   - string chapter_id
 * Approach:
 *   Validates inputs and executes explicit local logic for unlock_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from unlock_chapter.
 */
int unlock_chapter(string chapter_id) {
  mapping player_data;
  string normalized;
  string *unlocked;

  normalized = normalize_key(chapter_id);

  if (normalized == "")
    return 0;

  if (!CHAPTER_D->chapter_exists(normalized))
    return 0;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  unlocked = player_data["unlocked_chapters"];

  if (!pointerp(unlocked))
    unlocked = ({});

  if (member_array(normalized, unlocked) == -1)
    unlocked += ({ normalized });

  player_data["unlocked_chapters"] = unlocked;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles set_display_name for this object.
 * Parameters:
 *   - string new_display_name
 * Approach:
 *   Validates inputs and executes explicit local logic for set_display_name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_display_name.
 */
int set_display_name(string new_display_name) {
  mapping player_data;

  if (!stringp(new_display_name))
    return 0;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["display_name"] = new_display_name;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles query_level for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns persisted avatar level with a defensive minimum of 1.
 * Side effects:
 *   May repair and persist missing or invalid level save data.
 * Returns:
 *   int result from query_level.
 */
int query_level() {
  mapping player_data;
  int level;
  int changed;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 1;

  level = normalize_level_value(player_data["level"]);
  changed = ensure_player_level(player_data);

  if (changed)
    save_player_data(player_data);

  return level;
}

/* Method Summary:
 * Purpose:
 *   Handles set_level for this object.
 * Parameters:
 *   - int new_level
 * Approach:
 *   Persists avatar level while enforcing a minimum of 1.
 * Side effects:
 *   Updates avatar save data.
 * Returns:
 *   int result from set_level.
 */
int set_level(int new_level) {
  mapping player_data;
  int normalized_level;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  normalized_level = normalize_level_value(new_level);
  player_data["level"] = normalized_level;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles brief for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for brief.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from brief.
 */
int brief() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  return player_data["brief"];
}

/* Method Summary:
 * Purpose:
 *   Handles set_brief for this object.
 * Parameters:
 *   - int state
 * Approach:
 *   Validates inputs and executes explicit local logic for set_brief.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_brief.
 */
int set_brief(int state) {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  if (state)
    player_data["brief"] = 1;
  else
    player_data["brief"] = 0;

  return save_player_data(player_data);
}

/* Method Summary:
 * Purpose:
 *   Handles toggle_brief for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for toggle_brief.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from toggle_brief.
 */
int toggle_brief() {
  mapping player_data;
  int brief;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  brief = player_data["brief"];

  if (brief)
    player_data["brief"] = 0;
  else
    player_data["brief"] = 1;

  if (!save_player_data(player_data))
    return 0;

  return player_data["brief"];
}

/* Method Summary:
 * Purpose:
 *   Handles last_played for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for last_played.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from last_played.
 */
int last_played() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  return player_data["last_played"];
}

/* Method Summary:
 * Purpose:
 *   Handles is_wizard for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for is_wizard.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_wizard.
 */
int is_wizard() {
  mapping player_data;
  int is_wizard;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  is_wizard = player_data["is_wizard"];

  if (intp(is_wizard) && is_wizard == 1)
    return 1;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles set_last_played for this object.
 * Parameters:
 *   - int last_played
 * Approach:
 *   Validates inputs and executes explicit local logic for set_last_played.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_last_played.
 */
int set_last_played(int last_played) {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["last_played"] = last_played;

  return save_player_data(player_data);
}
