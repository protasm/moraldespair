/*
 * Virtual object handler for rooms.
 */
object compile_object(string filename) {
  object room;
  string id;

  if (sscanf(filename, "wilderness_room#%s", id) != 1) {
    return 0;
  }

  room = clone_object("room/wilderness_room");
  if (!room) {
    return 0;
  }

  room->set_room_id(id);

  return room;
}
