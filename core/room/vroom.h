#ifndef _CORE_ROOM_VROOM_H_
#define _CORE_ROOM_VROOM_H_

mapping room_data();
void set_descriptions();
void set_room_path(string path);
string room_id();
mapping link_can_enter(object actor, object link);
string link_endpoint_id();

#endif

/* Alphabetized forward declarations for core/room/vroom.c */

/* Alphabetized forward declarations (ctags) for core/room/vroom.c */
void create();
mapping link_can_enter(object actor, object link);
string link_endpoint_id();
mapping room_data();
string room_id();
void set_descriptions();
void set_room_path(string path);
