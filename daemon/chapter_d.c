#include <globals.h>

#include "chapter_d.h"

mapping chapter_registry;
string latest_chapter_id;

string normalize_id(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string normalize_path(string path) {
  if (!stringp(path))
    return "";

  if (path == "")
    return "";

  if (path[0] != '/')
    return "/" + path;

  return path;
}

void register_chapter(string id, string title, string description,
                      string root, string start_room) {
  object chapter;
  string normalized;

  normalized = normalize_id(id);

  /* We normalize IDs to keep saved player data stable and comparable. */
  if (normalized == "")
    return;

  /* Prevent accidental overrides so chapter metadata stays authoritative. */
  if (chapter_exists(normalized))
    return;

  chapter = new("/core/chapter");

  if (!objectp(chapter))
    return;

  /* Store display data in a dedicated object to avoid path coupling. */
  chapter->set_title(title);
  chapter->set_description(description);
  chapter->set_root(normalize_path(root));
  chapter->set_start_room(normalize_path(start_room));

  chapter_registry[normalized] = chapter;

  return;
}

void create() {
  chapter_registry = ([]);
  /* The daemon owns the global notion of "latest" for refactor safety. */
  latest_chapter_id = "prologue";

  register_chapter(
    "prologue",
    "Prologue: Despair",
    "Two hundred years have passed....",
    "/chapter/prologue",
    "/chapter/prologue/area/ruined/room/sanctuary"
  );
}

int chapter_exists(string id) {
  id = normalize_id(id);

  if (id == "")
    return 0;

  if (!mapp(chapter_registry))
    return 0;

  if (!objectp(chapter_registry[id]))
    return 0;

  return 1;
}

string query_latest_chapter() {
  if (!stringp(latest_chapter_id))
    return "";

  return latest_chapter_id;
}

string get_chapter_root(string id) {
  object chapter;

  if (!chapter_exists(id))
    return "";

  chapter = chapter_registry[normalize_id(id)];

  if (!objectp(chapter))
    return "";

  return chapter->query_root();
}

string get_start_room(string id) {
  object chapter;

  if (!chapter_exists(id))
    return "";

  chapter = chapter_registry[normalize_id(id)];

  if (!objectp(chapter))
    return "";

  return chapter->query_start_room();
}

int can_player_access(object player, string id) {
  string normalized;
  string *unlocked;

  normalized = normalize_id(id);

  /* Validate against daemon data before looking at player state. */
  if (!chapter_exists(normalized))
    return 0;

  /* The most recent global chapter is always playable. */
  if (normalized == latest_chapter_id)
    return 1;

  if (!objectp(player))
    return 0;

  if (function_exists("query_unlocked_chapters", player)) {
    unlocked = player->query_unlocked_chapters();

    if (member_array(normalized, unlocked) != -1)
      return 1;
  }

  if (function_exists("query_current_chapter", player))
    if (player->query_current_chapter() == normalized)
      return 1;

  return 0;
}

string resolve_player_chapter(object player) {
  string current, resolved;

  /* Default to the global chapter so empty saves still load cleanly. */
  resolved = latest_chapter_id;

  if (!objectp(player))
    return resolved;

  if (function_exists("query_current_chapter", player))
    current = player->query_current_chapter();
  else
    current = "";

  if (chapter_exists(current) && can_player_access(player, current))
    return current;

  /* Keep the player save aligned with the daemon's source of truth. */
  if (chapter_exists(resolved)) {
    if (function_exists("set_current_chapter", player))
      player->set_current_chapter(resolved);

    return resolved;
  }

  return "";
}

string resolve_player_start_room(object player) {
  string chapter_id, start_room;

  chapter_id = resolve_player_chapter(player);
  start_room = get_start_room(chapter_id);

  if (start_room == "")
    start_room = START_ROOM;

  return start_room;
}
