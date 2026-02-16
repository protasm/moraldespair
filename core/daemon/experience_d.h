/* Companion header file. */

/* Alphabetized forward declarations for core/daemon/experience_d.c */
void create();
string actor_name_for_event(object actor);
int event_is_valid(mapping event);
void emit_avatar_presence_arrival(object actor, object room);
void emit_avatar_presence_departure(object actor, object room);
void emit_combat_impact(
  object actor, object target, object room, string attack_label, int amount
);
void emit_environment_ambience(
  object actor, object room, string kind, string line, string modality
);
void emit_link_action_feedback(
  object actor, object room, string feedback_text, string verb
);
void emit_movement_arrival(object actor, object destination, string direction);
void emit_movement_departure(object actor, object origin, string direction);
void emit_room_event(object actor, object room, mapping event);
void emit_speech_event(object actor, object room, string spoken_text);
string ensure_line_break(string line);
string format_arrival_direction(string direction);
mapping merge_sensor_profiles(mapping base_profile, mapping override_profile);
int modality_is_valid(string modality);
string modality_combo_key(string *modalities);
mapping modality_registry();
mapping movement_event_payload(
  object actor,
  string phase,
  object room,
  string direction
);
int object_can_perceive_facet(object observer, mapping facet);
mapping object_sensor_profile(object observer);
string object_sensory_form(object observer);
mapping perceive_event(object observer, mapping event);
int room_light_level(object room);
int route_event_to_observer(object observer, mapping event);
string *unique_modalities(string *modalities);
mapping default_sensor_profile_for_form(string form);
string *supported_modalities();
int is_valid_form(string form);

/* Alphabetized forward declarations (ctags) for core/daemon/experience_d.c */
void create();
string actor_name_for_event(object actor);
mapping default_sensor_profile_for_form(string form);
void emit_avatar_presence_arrival(object actor, object room);
void emit_avatar_presence_departure(object actor, object room);
void emit_combat_impact(
  object actor, object target, object room, string attack_label, int amount
);
void emit_environment_ambience(
  object actor, object room, string kind, string line, string modality
);
void emit_link_action_feedback(
  object actor, object room, string feedback_text, string verb
);
void emit_movement_arrival(object actor, object destination, string direction);
void emit_movement_departure(object actor, object origin, string direction);
void emit_room_event(object actor, object room, mapping event);
void emit_speech_event(object actor, object room, string spoken_text);
string ensure_line_break(string line);
int event_is_valid(mapping event);
string format_arrival_direction(string direction);
int is_valid_form(string form);
mapping merge_sensor_profiles(mapping base_profile, mapping override_profile);
int modality_is_valid(string modality);
string modality_combo_key(string *modalities);
mapping modality_registry();
mapping movement_event_payload(
  object actor,
  string phase,
  object room,
  string direction
);
int object_can_perceive_facet(object observer, mapping facet);
mapping object_sensor_profile(object observer);
string object_sensory_form(object observer);
mapping perceive_event(object observer, mapping event);
int room_light_level(object room);
int route_event_to_observer(object observer, mapping event);
string *supported_modalities();
string *unique_modalities(string *modalities);
