#define ROOM_DATA_D "/daemon/room_data_d"

inherit "/chapter/prologue/std/room";

string room_path;

void set_descriptions() {
  object room_data_daemon;
  mapping room_data;
  string short_name, long_name;

  if (!stringp(room_path) || room_path == "")
    return;

  room_data_daemon = find_object(ROOM_DATA_D);

  if (!objectp(room_data_daemon))
    room_data_daemon = load_object(ROOM_DATA_D);

  room_data = 0;

  if (objectp(room_data_daemon))
    room_data = room_data_daemon->room_data(room_path);

  short_name = 0;
  long_name = 0;

  if (mapp(room_data)) {
    short_name = room_data["short"];
    long_name = room_data["long"];
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

string link_endpoint_id() {
  if (!stringp(room_path) || room_path == "")
    return base_name(this_object());

  return room_path;
}
