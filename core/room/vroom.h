#ifndef _CORE_ROOM_VROOM_H_
#define _CORE_ROOM_VROOM_H_

mapping room_data();
void set_descriptions();
void set_room_path(string path);
string room_id();
mapping link_can_enter(object actor, object link);
string link_endpoint_id();

#endif
