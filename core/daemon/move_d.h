object try_move_label(object avatar, string label);
object try_move(object avatar, string direction);

/* Alphabetized forward declarations for core/daemon/move_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/move_d.c */
string actor_name_for_message(object actor);
void announce_arrival(object actor, object destination, string direction);
void announce_departure(object actor, object origin, string direction);
void announce_transition(
  object actor,
  object origin,
  object destination,
  object link,
  string departure_direction
);
int combat_amount_from_mutation(mapping mutation);
string direction_for_link_from_room(object room, object link);
void emit_combat_events_from_mutations(
  object actor,
  object room,
  mixed mutations
);
string endpoint_id_for_room(object room);
object try_move(object avatar, string direction);
object try_move_label(object avatar, string label);
