/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/chapter_d.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include <globals.h>
 *   - #include "chapter_d.h"
 */

#include <globals.h>

#include "chapter_d.h"

mapping chapter_registry;
string latest_chapter_id;

/* Method Summary:
 * Purpose:
 *   Handles normalize_id for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_id.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_id.
 */
string normalize_id(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

/* Method Summary:
 * Purpose:
 *   Handles normalize_path for this object.
 * Parameters:
 *   - string path
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_path.
 */
string normalize_path(string path) {
  if (!stringp(path))
    return "";

  if (path == "")
    return "";

  if (path[0] != '/')
    path = "/" + path;

  if (sizeof(path) > 2 && path[<2..<1] == ".c")
    path = path[0..<3];

  return path;
}

/* Method Summary:
 * Purpose:
 *   Handles register_chapter for this object.
 * Parameters:
 *   - string id, string title, string description,
 * Approach:
 *   Validates inputs and executes explicit local logic for register_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from register_chapter.
 */
void register_chapter(string id, string title, string description,
                      string root, string start_room) {
  object chapter;
  string normalized;

  normalized = normalize_id(id);

  /* We normalize IDs to keep saved avatar data stable and comparable. */
  if (normalized == "")
    return;

  /* Prevent accidental overrides so chapter metadata stays authoritative. */
  if (chapter_exists(normalized))
    return;

  chapter = new("/core/chapter/chapter");

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
  chapter_registry = ([]);
  /* The daemon owns the global notion of "latest" for refactor safety. */
  latest_chapter_id = "prologue";

  register_chapter(
    "prologue",
    "Prologue: Despair",
    "Two hundred years have passed....",
    "/chapter/prologue",
    START_ROOM,
  );
}

/* Method Summary:
 * Purpose:
 *   Handles chapter_exists for this object.
 * Parameters:
 *   - string id
 * Approach:
 *   Validates inputs and executes explicit local logic for chapter_exists.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from chapter_exists.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles latest_chapter for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for latest_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from latest_chapter.
 */
string latest_chapter() {
  if (!stringp(latest_chapter_id))
    return "";

  return latest_chapter_id;
}

/* Method Summary:
 * Purpose:
 *   Handles get_chapter_root for this object.
 * Parameters:
 *   - string id
 * Approach:
 *   Validates inputs and executes explicit local logic for get_chapter_root.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from get_chapter_root.
 */
string get_chapter_root(string id) {
  object chapter;

  if (!chapter_exists(id))
    return "";

  chapter = chapter_registry[normalize_id(id)];

  if (!objectp(chapter))
    return "";

  return chapter->root();
}

/* Method Summary:
 * Purpose:
 *   Handles get_start_room for this object.
 * Parameters:
 *   - string id
 * Approach:
 *   Validates inputs and executes explicit local logic for get_start_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from get_start_room.
 */
string get_start_room(string id) {
  object chapter;

  if (!chapter_exists(id))
    return "";

  chapter = chapter_registry[normalize_id(id)];

  if (!objectp(chapter))
    return "";

  return chapter->start_room();
}

/* Method Summary:
 * Purpose:
 *   Handles can_avatar_access for this object.
 * Parameters:
 *   - object avatar, string id
 * Approach:
 *   Validates inputs and executes explicit local logic for can_avatar_access.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from can_avatar_access.
 */
int can_avatar_access(object avatar, string id) {
  string normalized;
  string *unlocked;

  normalized = normalize_id(id);

  /* Validate against daemon data before looking at player state. */
  if (!chapter_exists(normalized))
    return 0;

  /* The most recent global chapter is always playable. */
  if (normalized == latest_chapter_id)
    return 1;

  if (!objectp(avatar))
    return 0;

  if (function_exists("unlocked_chapters", avatar)) {
    unlocked = avatar->unlocked_chapters();

    if (member_array(normalized, unlocked) != -1)
      return 1;
  }

  if (function_exists("current_chapter", avatar))
    if (avatar->current_chapter() == normalized)
      return 1;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles resolve_avatar_chapter for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Validates inputs and executes explicit local logic for resolve_avatar_chapter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from resolve_avatar_chapter.
 */
string resolve_avatar_chapter(object avatar) {
  string current, resolved;

  /* Default to the global chapter so empty saves still load cleanly. */
  resolved = latest_chapter_id;

  if (!objectp(avatar))
    return resolved;

  if (function_exists("current_chapter", avatar))
    current = avatar->current_chapter();
  else
    current = "";

  if (chapter_exists(current) && can_avatar_access(avatar, current))
    return current;

  /* Keep the avatar save aligned with the daemon's source of truth. */
  if (chapter_exists(resolved)) {
    if (function_exists("set_current_chapter", avatar))
      avatar->set_current_chapter(resolved);

    return resolved;
  }

  return "";
}

/* Method Summary:
 * Purpose:
 *   Handles resolve_avatar_start_room for this object.
 * Parameters:
 *   - object avatar
 * Approach:
 *   Validates inputs and executes explicit local logic for resolve_avatar_start_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from resolve_avatar_start_room.
 */
string resolve_avatar_start_room(object avatar) {
  string chapter_id, start_room;

  chapter_id = resolve_avatar_chapter(avatar);
  start_room = get_start_room(chapter_id);

  if (start_room == "")
    start_room = START_ROOM;

  return start_room;
}

int can_player_access(object avatar, string id) {
  return can_avatar_access(avatar, id);
}

string resolve_player_chapter(object avatar) {
  return resolve_avatar_chapter(avatar);
}

string resolve_player_start_room(object avatar) {
  return resolve_avatar_start_room(avatar);
}
