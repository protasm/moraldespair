#define WILDERNESS_ROOM_TEMPLATE "/chapter/prologue/std/wilderness_room"
#define DATA_ROOM_TEMPLATE "/chapter/prologue/std/data_room"

/*
 * Virtual object handler for rooms.
 */
object compile_object(string filename) {
  object room;
  string id, room_path, base_id;

  id = "";

  if (sscanf(filename, "wilderness_room#%s", id) == 1) {
    if (sscanf(id, "%s.c", base_id) == 1)
      id = base_id;

    room = clone_object(WILDERNESS_ROOM_TEMPLATE);

    if (!objectp(room))
      return 0;

    room->set_room_id(id);

    return room;
  }

  room_path = "";

  if (sscanf(filename, "data_room#%s", room_path) == 1) {
    if (sscanf(room_path, "%s.c", base_id) == 1)
      room_path = base_id;

    room = clone_object(DATA_ROOM_TEMPLATE);

    if (!objectp(room))
      return 0;

    room->set_room_path(room_path);

    return room;
  }

  return 0;
}
