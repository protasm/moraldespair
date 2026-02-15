
/* Alphabetized forward declarations for core/room/room.c */

/* Alphabetized forward declarations (ctags) for core/room/room.c */
void add_link(string label, object link);
void create();
object link(string label);
object link_cache();
mapping link_can_enter(object actor, object link);
string *link_labels();
string long();
void post_action(object action);
void post_arrive(object exit);
void post_leave(object exit);
int pre_action(object action);
int pre_arrive(object exit);
int pre_leave(object exit);
string room_id_value(mapping room_details);
string short();
mapping terrain_room_data();
string terrain_long_value(mapping room_details);
