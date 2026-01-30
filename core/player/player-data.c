#include <globals.h>

string player_name;
object player_object, account_object;

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string player_file_path() {
  string username, player;

  username = account_object->username();
  player = normalize_key(player_name);

  if (username == "" || player == "")
    return "";

  return "/a/" + username + "/" + player + ".o";
}

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

object query_player() {
  return player_object;
}

void set_player(object player) {
  player_object = player;

  return;
}

object query_account() {
  return account_object;
}

void set_account(object new_account) {
  account_object = new_account;

  return;
}

string query_name() {
  return player_name;
}

void set_name(string new_name) {
  player_name = normalize_key(new_name);

  return;
}

string query_display_name() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return "";

  return player_data["display_name"];
}

string query_current_chapter() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return "";

  if (!stringp(player_data["current_chapter"]))
    return "";

  return player_data["current_chapter"];
}

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

string *query_unlocked_chapters() {
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

int query_brief() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  return player_data["brief"];
}

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

int query_last_played() {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  return player_data["last_played"];
}

int set_last_played(int last_played) {
  mapping player_data;

  player_data = load_player_data();

  if (!mapp(player_data))
    return 0;

  player_data["last_played"] = last_played;

  return save_player_data(player_data);
}
