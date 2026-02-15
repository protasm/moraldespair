#define WILD_D "/daemon/wild_d"

inherit "/core/room/room";

#include <link.h>

#include "wild_room.h"

/*
 * Virtual Wild room. It stores only a room id and queries the daemon
 * for all state, keeping room data centralized and easy to extend.
 */
string wild_room_id, terrain_code;
string room_path;

void create() {
  ::create();

  if (wild_room_id)
    set_descriptions();
}

void set_room_id(string id) {
  object cache;

  wild_room_id = id;

  set_descriptions();
  cache = link_cache();

  if (objectp(cache) && function_exists("init_for_room", cache))
    cache->init_for_room(this_object());

  return;
}

void set_room_path(string path) {
  string normalized_path;
  string id;
  object cache;

  if (!stringp(path))
    return;

  normalized_path = trim(path);

  if (normalized_path == "")
    return;

  if (normalized_path[0] != '/')
    normalized_path = "/" + normalized_path;

  if (sizeof(normalized_path) > 2 && normalized_path[<2..<1] == ".c")
    normalized_path = normalized_path[0..<3];

  room_path = normalized_path;
  id = "";

  if (sscanf(room_path, "%s#%s", normalized_path, id) == 2)
    wild_room_id = id;
  else
    wild_room_id = "";

  set_descriptions();
  cache = link_cache();

  if (objectp(cache) && function_exists("init_for_room", cache))
    cache->init_for_room(this_object());

  return;
}

string room_id() {
  return wild_room_id;
}

string terrain() {
  return terrain_code;
}

string link_endpoint_id() {
  string endpoint_id;

  endpoint_id = "";

  if (stringp(room_path) && room_path != "")
    endpoint_id = room_path;
  else
    endpoint_id = base_name(this_object());

  return endpoint_id;
}

void set_descriptions() {
  object wild_daemon;
  mapping terrain_info;
  mixed long_data;
  string *long_options;
  string short_name, long_name, terrain_from_daemon;
  int long_index;

  if (!wild_room_id) return;

  terrain_code = "default";
  terrain_info = 0;
  short_name = 0;
  long_name = 0;
  terrain_from_daemon = 0;
  wild_daemon = find_object(WILD_D);

  if (!objectp(wild_daemon))
    wild_daemon = load_object(WILD_D);

  /*
   * Descriptions should never fail room creation. If wild_d is not
   * available, this room still resolves with default prose.
   */
  if (objectp(wild_daemon)) {
    terrain_from_daemon = wild_daemon->terrain(wild_room_id);

    if (stringp(terrain_from_daemon) && terrain_from_daemon != "")
      terrain_code = terrain_from_daemon;

    terrain_info = wild_daemon->terrain_info(terrain_code);

    if (!mapp(terrain_info))
      terrain_info = wild_daemon->terrain_info("default");
  }

  if (mapp(terrain_info)) {
    short_name = terrain_info["short"];
    long_data = terrain_info["long"];

    if (pointerp(long_data)) {
      long_options = long_data;

      if (sizeof(long_options) > 0) {
        long_index = random(sizeof(long_options));
        long_name = long_options[long_index];
      }
    } else if (stringp(long_data))
      long_name = long_data;
  }

  if (stringp(short_name))
    short_desc = short_name;
  else
    short_desc = "The Wild";

  if (stringp(long_name))
    long_desc = long_name;
  else
    long_desc = "The land here is quiet and open. No clear paths remain.";

  return;
}

void set_exits() {
  /*
   * Exits are resolved via LINK_D + MOVE_D.
   * Wild exits remain daemon-backed data and do not write legacy
   * dest_dir mappings in this room implementation.
   */
  return;
}

mapping link_can_enter(object actor, object link) {
  object wild_daemon;
  mapping terrain_info;
  string current_terrain;
  string traverse_failure;
  string blocked_message;
  int traverse_cost;

  if (objectp(actor) && wizardp(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  current_terrain = terrain();

  if (!stringp(current_terrain))
    current_terrain = "";

  wild_daemon = find_object(WILD_D);

  if (!objectp(wild_daemon))
    wild_daemon = load_object(WILD_D);

  terrain_info = 0;

  if (objectp(wild_daemon) && current_terrain != "")
    terrain_info = wild_daemon->terrain_info(current_terrain);

  if (!mapp(terrain_info))
    terrain_info = ([]);

  traverse_cost = terrain_info["traverse_cost"];

  if (!intp(traverse_cost))
    traverse_cost = 0;

  if (traverse_cost >= 0)
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  traverse_failure = terrain_info["traverse_failure"];

  if (stringp(traverse_failure) && traverse_failure != "")
    blocked_message = traverse_failure;
  else
    blocked_message = "That terrain is not passable right now.";

  return ([
    LINK_RESULT_OUTCOME : LINK_OUTCOME_DENY,
    LINK_RESULT_MESSAGE : blocked_message,
    LINK_RESULT_REDIRECT : "",
    LINK_RESULT_COST : 0,
    LINK_RESULT_MUTATIONS : ({ })
  ]);
}
