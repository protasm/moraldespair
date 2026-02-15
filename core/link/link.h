#ifndef _LINK_H
#define _LINK_H

/****************************************************************************
 * Link traversal outcomes
 *
 * Outcome describes the spatial result of a traversal attempt.
 * Mutations, cost, and narration are orthogonal and may accompany
 * ANY outcome.
 ****************************************************************************/

/* Traversal denied; actor remains in origin */
#define LINK_OUTCOME_DENY            0

/* Traversal succeeded normally */
#define LINK_OUTCOME_ALLOW           1

/* Traversal succeeded, then actor was forced back to origin */
#define LINK_OUTCOME_ALLOW_REVERSE   2

/* Traversal succeeded, then actor was redirected elsewhere */
#define LINK_OUTCOME_ALLOW_REDIRECT  3


/****************************************************************************
 * Link result mapping keys
 *
 * A traversal attempt returns a mapping with some or all of these keys.
 ****************************************************************************/

/*
 * Required:
 *   One of LINK_OUTCOME_* above.
 */
#define LINK_RESULT_OUTCOME          "outcome"

/*
 * Optional:
 *   Actor-facing message describing link- or gate-owned events.
 *   (Rooms/actors narrate their own agency separately.)
 */
#define LINK_RESULT_MESSAGE          "message"

/*
 * Optional:
 *   String destination for redirects (ALLOW_REDIRECT only).
 */
#define LINK_RESULT_REDIRECT         "redirect"

/*
 * Optional:
 *   Environment object representing the intermediate destination
 *   reached before a redirect (for trapdoors, chutes, etc.).
 */
#define LINK_RESULT_INTERMEDIATE     "intermediate"

/*
 * Optional:
 *   Traversal cost (e.g., stamina, fatigue, time).
 *   Interpretation is game-specific.
 */
#define LINK_RESULT_COST             "cost"

/*
 * Optional:
 *   Side effects / mutations applied as a result of traversal.
 *   May be a mapping or an array, depending on your effect system.
 *
 * Examples:
 *   ([ "stamina" : -3 ])
 *   ({ ([ "type":"damage", "amount":5 ]) })
 */
#define LINK_RESULT_MUTATIONS        "mutations"

#endif /* _LINK_H */


/* Alphabetized forward declarations for core/link/link.c */

/* Alphabetized forward declarations (ctags) for core/link/link.c */
mapping _build_action_groups(object actor, string endpoint_id);
mapping _match_action_args(string args, mapping verb_actions);
mapping action_match(object actor, string verb, string args, string endpoint_id);
void add_gate(object gate_obj);
mapping allow_result();
int allows_path(string origin_id, string destination_id);
string appearance(string endpoint);
mapping build_result(
  int outcome, string message, string redirect,
  int cost, mixed mutations
);
mapping can_enter(object actor, object destination);
mapping can_exit(object actor, object origin);
mapping check_gates(object actor, string origin_id, string destination_id);
mapping check_link(object actor, string origin_id, string destination_id);
void create();
mapping deny_result(string message, int cost, mixed mutations);
string describe_from_endpoint(string endpoint_id);
string direction_label(string endpoint);
mapping dirs();
string endpoint_a();
string endpoint_b();
string endpoint_id_for_room(object room);
int endpoint_index(string endpoint);
object gate();
string gate_status_line(string endpoint_id);
object *gates();
int handle_action(object actor, string verb, string args, string endpoint_id);
int is_allowed_result(mapping result);
int is_endpoint(string endpoint);
string *link_verbs(object actor, string endpoint_id);
mapping merge_side_effects(mapping dst, mapping src);
mixed meta(string key);
mapping on_enter(object actor, object origin, object destination);
void on_exit(object actor, object origin, object destination);
string other_endpoint(string endpoint);
int perform_link_action(object actor, string verb, string args, string endpoint_id);
object resolve_destination(string destination_id);
void set_appearance(string description);
void set_appearances(mapping appearances);
void set_bidirectional();
void set_direction_label(string endpoint, string label);
void set_dirs(mapping dirs);
void set_endpoint_appearance(string endpoint, string description);
void set_endpoints(string first, string second);
void set_meta(string key, mixed value);
void set_one_way(string from_endpoint, string to_endpoint);
void show_actor_location(object actor);
void show_resolution_debug(object actor, string text);
mapping traverse(object actor, object origin);
