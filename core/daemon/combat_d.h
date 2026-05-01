/* Companion header file. */

/* Alphabetized forward declarations for core/daemon/combat_d.c */
int handle_input(object avatar, string raw);
int start_fight(object attacker, object defender);

/* Alphabetized forward declarations (ctags) for core/daemon/combat_d.c */
void begin_player_turn(string fight_id, object actor);
int auto_combat_enabled(object actor);
int choose_default_slot(mapping state);
int choose_highest_slot(mapping state);
int choose_npc_slot(mapping fight, object actor);
void clear_combat_flags(object actor);
mapping default_avatar_abilities();
mapping default_npc_abilities();
int execute_action(string fight_id, object actor, int slot, int timed_out);
void finish_fight(string fight_id, object winner, object loser);
string format_action_line(
  mapping fight,
  object actor,
  object target,
  mapping ability
);
string format_prompt_line(mapping state);
int handle_input(object avatar, string raw);
int is_combatant_ready(mapping state);
int is_valid_combat_target(object attacker, object target);
mapping participant_state_for(object actor);
void player_turn_timeout(string fight_id, object actor, int timeout_token);
void process_fight(string fight_id);
void register_combat_flags(string fight_id, object actor);
int roll_damage(mapping ability);
string source_name(object actor);
int start_fight(object attacker, object defender);
string status_for_slot(mapping cooldowns, int slot);
int tick_actor_cooldowns(mapping state);
object turn_ready_actor(mapping fight);
void write_combat_event(object avatar, string text, string kind);
void write_fight_intro(mapping fight);
