/* Companion header file. */

/* Alphabetized forward declarations for core/npc/npc.c */

void add_id(string new_id);
void add_ids(string *new_ids);
int attempt_random_move();
void catch_tell(string message);
void create();
void emit_fidget();
void experience(mapping event);
void heart_beat();
int id(string an_id);
int is_living();
int is_npc();
string long();
void mobility_tick();
int move(mixed dest);
void move_or_destruct(object dest);
string name();
void net_dead();
int pop_path_memory_to(string room_path);
void push_path_memory(string room_path);
int query_level();
int query_mobility_enabled();
int query_mobility_move_chance();
string *query_path_memory();
int query_path_memory_max();
string query_spawn_anchor();
void remove();
void schedule_mobility_tick();
mapping sensory_profile();
string sensory_form();
void set_fidget_text(string text);
void set_fidget_texts(string *texts);
void set_level(int new_level);
void set_long(string new_long);
void set_mobility_delay_range(int min_seconds, int max_seconds);
void set_mobility_enabled(int enabled);
void set_mobility_move_chance(int percent);
void set_name(string new_name);
void set_path_memory_max(int max_entries);
void set_sensory_profile(mapping profile_override);
int set_sensory_form(string new_form);
void set_spawn_anchor(string anchor_id);
void set_short(string new_short);
string short();
string short_for(object observer);
