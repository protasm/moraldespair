object try_move_label(object player, string label);
object try_move(object player, string direction);

/* Alphabetized forward declarations for core/daemon/move_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/move_d.c */
string actor_name_for_message(object actor);
void announce_arrival(object player, object destination, string direction);
void announce_departure(object player, object origin, string direction);
string direction_for_link_from_room(object room, object link);
string endpoint_id_for_room(object room);
object try_move(object player, string direction);
object try_move_label(object player, string label);
