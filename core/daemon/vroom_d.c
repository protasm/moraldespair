/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/vroom_d.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "vroom_d.h"
 */

#define VROOM_TEMPLATE "/core/room/vroom"

#include "vroom_d.h"

/* Method Summary:
 * Purpose:
 *   Handles wizard_virtual_debug for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for wizard_virtual_debug.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from wizard_virtual_debug.
 */
void wizard_virtual_debug(string message) {
  string line;

  if (!stringp(message) || message == "")
    return;

  line = ctime(time()) + " " + message + "\n";
  write_file("/log/virtual_room_debug", line);

  return;
}

/*
 * Virtual object handler for rooms.
 */
/* Method Summary:
 * Purpose:
 *   Handles compile_object for this object.
 * Parameters:
 *   - string filename
 * Approach:
 *   Validates inputs and executes explicit local logic for compile_object.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from compile_object.
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
