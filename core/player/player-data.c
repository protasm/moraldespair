/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/player/player-data.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include <globals.h>
 */

#include <globals.h>

string player_name;
object player_object, account_object;

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
