#define ROOM_DATA_D "/daemon/room_data_d"

inherit "/core/room/room";

#include <link.h>

string room_path;

mapping room_data() {
  object room_data_daemon;
  mapping room_details;

  if (!stringp(room_path) || room_path == "")
    return 0;

  room_data_daemon = find_object(ROOM_DATA_D);

  if (!objectp(room_data_daemon))
    room_data_daemon = load_object(ROOM_DATA_D);

  room_details = 0;

  if (objectp(room_data_daemon))
    room_details = room_data_daemon->room_data(room_path);

  if (!mapp(room_details))
    return 0;

  return room_details;
}

void set_descriptions() {
  mapping room_details;
  mixed long_data;
  string *long_options;
  string short_name, long_name;
  int long_index;

  room_details = room_data();

  short_name = 0;
  long_name = 0;
  long_data = 0;
  long_options = ({ });
  long_index = 0;

  if (mapp(room_details)) {
    short_name = room_details["short"];
    long_data = room_details["long"];

    if (pointerp(long_data)) {
      long_options = long_data;

      if (sizeof(long_options) > 0) {
        long_index = random(sizeof(long_options));
        long_name = long_options[long_index];
      }
    } else if (stringp(long_data))
      long_name = long_data;
  }

  if (stringp(short_name) && short_name != "")
    short_desc = short_name;
  else
    short_desc = "Ruins";

  if (stringp(long_name) && long_name != "")
    long_desc = long_name;
  else
    long_desc = "The remains here are silent and abandoned.";

  return;
}

void create() {
  ::create();

  if (stringp(room_path) && room_path != "")
    set_descriptions();

  return;
}

void set_room_path(string path) {
  object cache;

  room_path = path;

  set_descriptions();
  cache = link_cache();

  if (objectp(cache) && function_exists("init_for_room", cache))
    cache->init_for_room(this_object());

  return;
}

string room_id() {
  return room_path;
}

mapping link_can_enter(object actor, object link) {
  mapping room_details;
  string traverse_failure;
  string blocked_message;
  int traverse_cost;

  if (objectp(actor) && wizardp(actor))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  room_details = room_data();

  if (!mapp(room_details))
    room_details = ([]);

  traverse_cost = room_details["traverse_cost"];

  if (!intp(traverse_cost))
    traverse_cost = 0;

  if (traverse_cost >= 0)
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  traverse_failure = room_details["traverse_failure"];

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

string link_endpoint_id() {
  if (!stringp(room_path) || room_path == "")
    return base_name(this_object());

  return room_path;
}
