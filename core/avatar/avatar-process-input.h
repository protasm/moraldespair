/* Companion header file. */

/* Alphabetized forward declarations for core/avatar/avatar-process-input.c */

/* Alphabetized forward declarations (ctags) for core/avatar/avatar-process-input.c */
int can_target_soul_object(object candidate);
int handle_soul_input(string verb, string arg);
string process_input(string raw);
string soul_actor_name(object actor);
string soul_apply_template(string template, string actor_name, string target_name);
void soul_broadcast(object actor, object target, string target_text, string room_text);
void soul_emit_to(object recipient, string text);
string soul_target_name(object target);
string soul_third_person_verb(string verb);
