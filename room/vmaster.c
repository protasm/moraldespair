#define WILDERNESS_D "/daemon/wilderness_d"

/*
 * Virtual object handler for rooms.
 */
object compile_object(string filename) {
  object room;
  string id;
  string base_id;

  if (sscanf(filename, "wilderness_room#%s", id) != 1) {
    return 0;
  }

  if (sscanf(id, "%s.c", base_id) == 1) {
    id = base_id;
  }

  WILDERNESS_D->debug_log("compile_object: " + filename + " id=" + id);

  room = clone_object("room/wilderness_room");
  if (!room) {
    return 0;
  }

  room->set_room_id(id);

  return room;
}
