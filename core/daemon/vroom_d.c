#define VROOM_TEMPLATE "/core/room/vroom"

#include "vroom_d.h"

void wizard_virtual_debug(string message) {
  object *online_users;
  object user;
  string line;
  int is_wizard_user;
  int i;

  if (!stringp(message) || message == "")
    return;

  line = ctime(time()) + " " + message + "\n";
  write_file("/log/virtual_room_debug", line);

  online_users = users();

  if (!pointerp(online_users))
    return;

  for (i = 0; i < sizeof(online_users); i++) {
    user = online_users[i];

    if (!objectp(user))
      continue;

    is_wizard_user = 0;

    if (wizardp(user))
      is_wizard_user = 1;
    else if (function_exists("is_wizard", user) && user->is_wizard())
      is_wizard_user = 1;

    if (!is_wizard_user)
      continue;

    tell_object(user, "[virtual-debug] " + message + "\n");
  }

  return;
}

/*
 * Virtual object handler for rooms.
 */
object compile_object(string filename) {
  object room;
  string room_path, base_id;

  room_path = "";

  if (sscanf(filename, "vroom#%s", room_path) == 1) {
    wizard_virtual_debug("vroom_d compile vroom request: " + filename);

    if (sscanf(room_path, "%s.c", base_id) == 1)
      room_path = base_id;

    room = clone_object(VROOM_TEMPLATE);

    if (!objectp(room)) {
      wizard_virtual_debug("vroom_d vroom clone failed: path=" + room_path);
      return 0;
    }

    room->set_room_path(room_path);
    wizard_virtual_debug("vroom_d vroom clone created: " + file_name(room));

    return room;
  }

  /*
   * Backward compatibility while transitioning aliases to vroom.
   */
  if (sscanf(filename, "area_room#%s", room_path) == 1) {
    wizard_virtual_debug("vroom_d compile area_room alias request: " + filename);

    if (sscanf(room_path, "%s.c", base_id) == 1)
      room_path = base_id;

    room = clone_object(VROOM_TEMPLATE);

    if (!objectp(room)) {
      wizard_virtual_debug("vroom_d area_room alias clone failed: path=" + room_path);
      return 0;
    }

    room->set_room_path(room_path);
    wizard_virtual_debug("vroom_d area_room alias clone created: " + file_name(room));

    return room;
  }

  /*
   * Backward compatibility while transitioning from data_room to vroom.
   */
  if (sscanf(filename, "data_room#%s", room_path) == 1) {
    wizard_virtual_debug("vroom_d compile data_room request: " + filename);

    if (sscanf(room_path, "%s.c", base_id) == 1)
      room_path = base_id;

    room = clone_object(VROOM_TEMPLATE);

    if (!objectp(room)) {
      wizard_virtual_debug("vroom_d data_room alias clone failed: path=" + room_path);
      return 0;
    }

    room->set_room_path(room_path);
    wizard_virtual_debug("vroom_d data_room alias clone created: " + file_name(room));

    return room;
  }

  return 0;
}
