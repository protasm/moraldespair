inherit "/core/object";

#include <link.h>

/*
 * Link: transient "between-space" connecting two endpoints.
 *
 * - Endpoints are strings (paths/IDs), resolved lazily.
 * - Links may include a single Gate between endpoint A and endpoint B.
 * - Each gate is a /core/link_gate subclass with two sides.
 *
 * Narration:
 * - Link/Gate narrate topology (blocked by gate, directional flavor).
 * - Rooms/actors narrate room-owned agency (guards, hazards) via hooks.
 *
 * Mutations/effects/cost:
 * - Orthogonal to spatial outcome; any outcome may include effects/cost.
 */

string endpoint_a;
string endpoint_b;

/* Optional endpoint-specific direction labels (purely affordance/UI) */
mapping endpoint_labels; /* endpoint_path -> label string */
mapping link_meta;
mapping endpoint_appearances; /* endpoint_path -> description */
string default_appearance;

/* Optional gate between endpoints */
object gate;

/* Optional explicit directionality shortcut (you may later rely purely on gate) */
mapping allowed_paths; /* origin_id -> dest_id (if present); empty means bidirectional */

/* ------------------------------------------------------------ */

/*
 * void create()
 * Initialize link state with empty endpoints, labels, metadata, gate, and
 * default bidirectional paths.
 */
void create() {
  ::create();

  endpoint_a = "";
  endpoint_b = "";

  endpoint_labels = ([]);
  link_meta = ([]);
  endpoint_appearances = ([]);
  default_appearance = "It seems possible to go that way.";
  gate = 0;

  /* Default: bidirectional */
  allowed_paths = ([]);

  return;
}

void show_actor_location(object actor) {
  if (!objectp(actor))
    return;

  if (!userp(actor))
    return;

  if (function_exists("show_location", actor))
    actor->show_location(0, 0);
}

/* ------------------------------------------------------------ */
/* Endpoints */
/* ------------------------------------------------------------ */

/*
 * void set_endpoints(string first, string second)
 * Define the two endpoints once, and seed default bidirectional routing.
 */
void set_endpoints(string first, string second) {
  if (!stringp(first) || !stringp(second))
    return;

  if (endpoint_a != "" || endpoint_b != "")
    return;

  endpoint_a = first;
  endpoint_b = second;

  /* Default bidirectional unless explicitly constrained */
  allowed_paths = ([
    endpoint_a : endpoint_b,
    endpoint_b : endpoint_a
  ]);
}

/*
 * string query_endpoint_a()
 * Return the endpoint A id, or "" if it has not been set.
 */
string query_endpoint_a() { return endpoint_a; }

/*
 * string query_endpoint_b()
 * Return the endpoint B id, or "" if it has not been set.
 */
string query_endpoint_b() { return endpoint_b; }

/*
 * int is_endpoint(string endpoint)
 * Report whether the provided id matches either endpoint.
 */
int is_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return 0;

  return (endpoint == endpoint_a || endpoint == endpoint_b);
}

/*
 * string other_endpoint(string endpoint)
 * Return the opposite endpoint id, or "" if the input is not an endpoint.
 */
string other_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return "";

  if (endpoint == endpoint_a) return endpoint_b;

  if (endpoint == endpoint_b) return endpoint_a;

  return "";
}

/*
 * int endpoint_index(string endpoint)
 * Return the gate-facing side index (0 for A, 1 for B), or -1 if unknown.
 */
int endpoint_index(string endpoint) {
  if (endpoint == endpoint_a) return 0;

  if (endpoint == endpoint_b) return 1;

  return -1;
}

/* ------------------------------------------------------------ */
/* Labels (affordance only) */
/* ------------------------------------------------------------ */

/*
 * void set_direction_label(string endpoint, string label)
 * Store a user-facing direction label for a specific endpoint id.
 */
void set_direction_label(string endpoint, string label) {
  if (!stringp(endpoint) || !stringp(label))
    return;

  endpoint_labels[endpoint] = label;
}

/*
 * string query_direction_label(string endpoint)
 * Return the direction label for an endpoint, or "" when none is set.
 */
string query_direction_label(string endpoint) {
  if (!stringp(endpoint))
    return "";

  return endpoint_labels[endpoint];
}

/*
 * void set_dirs(mapping dirs)
 * Replace direction labels with a normalized string->string mapping.
 */
void set_dirs(mapping dirs) {
  mapping normalized;

  if (!mapp(dirs))
    return;

  normalized = ([ ]);

  foreach (mixed k, mixed v in dirs) {
    if (!stringp(k) || !stringp(v))
      continue;

    normalized[k] = v;
  }

  endpoint_labels = normalized;
}

/*
 * mapping query_dirs()
 * Return the direction-label mapping, or an empty mapping when unset.
 */
mapping query_dirs() {
  if (!mapp(endpoint_labels))
    return ([ ]);

  return endpoint_labels;
}

/* ------------------------------------------------------------ */
/* Appearance */
/* ------------------------------------------------------------ */

void set_appearance(string description) {
  if (!stringp(description))
    return;

  default_appearance = description;
}

void set_endpoint_appearance(string endpoint, string description) {
  if (!stringp(endpoint) || !stringp(description))
    return;

  endpoint_appearances[endpoint] = description;
}

void set_appearances(mapping appearances) {
  mapping normalized;

  if (!mapp(appearances))
    return;

  normalized = ([ ]);

  foreach (mixed k, mixed v in appearances) {
    if (!stringp(k) || !stringp(v))
      continue;

    normalized[k] = v;
  }

  endpoint_appearances = normalized;
}

string query_appearance(string endpoint) {
  string description;

  description = "";

  if (stringp(endpoint) && mapp(endpoint_appearances))
    description = endpoint_appearances[endpoint];

  if (!stringp(description) || description == "")
    description = default_appearance;

  return description;
}

string query_gate_status_line(string endpoint_id) {
  int endpoint_idx;
  int side;
  string name;
  string status;

  endpoint_idx = endpoint_index(endpoint_id);

  if (endpoint_idx < 0)
    return "";

  if (!objectp(gate))
    return "";

  side = gate->side_facing_endpoint(endpoint_idx);
  name = gate->query_name();

  if (!stringp(name) || name == "")
    name = "gate";

  status = "";

  if (function_exists("query_status", gate))
    status = gate->query_status(side);

  if (stringp(status))
    status = trim(status);

  if (stringp(status) && status != "")
    return "Visible that way: " + name + " [" + status + "].\n";

  return "Visible that way: " + name + ".\n";
}

string describe_from_endpoint(string endpoint_id) {
  string description;
  string gate_line;

  description = query_appearance(endpoint_id);

  if (!stringp(description) || description == "")
    description = default_appearance;

  if (description[<1] != '\n')
    description += "\n";

  gate_line = query_gate_status_line(endpoint_id);

  if (stringp(gate_line) && gate_line != "")
    description += gate_line;

  return description;
}

/*
 * void set_meta(string key, mixed value)
 * Store arbitrary metadata keyed by non-empty string.
 */
void set_meta(string key, mixed value) {
  if (!stringp(key) || key == "")
    return;

  if (!mapp(link_meta))
    link_meta = ([]);

  link_meta[key] = value;
}

/*
 * mixed query_meta(string key)
 * Return metadata for the given key, or 0 when missing.
 */
mixed query_meta(string key) {
  if (!stringp(key) || key == "")
    return 0;

  if (!mapp(link_meta))
    return 0;

  return link_meta[key];
}

/* ------------------------------------------------------------ */
/* Optional explicit directionality (may later be removed)
 * ------------------------------------------------------------ */

/*
 * void set_bidirectional()
 * Allow travel in both directions once endpoints are set.
 */
void set_bidirectional() {
  if (endpoint_a == "" || endpoint_b == "")
    return;

  allowed_paths = ([
    endpoint_a : endpoint_b,
    endpoint_b : endpoint_a
  ]);
}

/*
 * void set_one_way(string from_endpoint, string to_endpoint)
 * Restrict travel to the specified direction only.
 */
void set_one_way(string from_endpoint, string to_endpoint) {
  if (!stringp(from_endpoint) || !stringp(to_endpoint))
    return;

  allowed_paths = ([ from_endpoint : to_endpoint ]);
}

/*
 * int allows_path(string origin_id, string destination_id)
 * Report whether the origin->destination pairing is permitted.
 */
int allows_path(string origin_id, string destination_id) {
  /* If allowed_paths is not set, default to bidirectional */
  if (!mapp(allowed_paths) || !sizeof(allowed_paths))
    return (other_endpoint(origin_id) == destination_id);

  return (allowed_paths[origin_id] == destination_id);
}

/* ------------------------------------------------------------ */
/* Gate
 * ------------------------------------------------------------ */

/*
 * void add_gate(object gate_obj)
 * Replace any existing gate and set a link back-reference if supported.
 */
void add_gate(object gate_obj) {
  if (!objectp(gate_obj))
    return;

  gate = gate_obj;

  /* Optional: if your gate objects want a backref, you can add set_link() later */
  if (function_exists("set_link", gate))
    gate->set_link(this_object());
}

/*
 * object query_gate()
 * Return the gate object, or 0 when none exists.
 */
object query_gate() {
  if (!objectp(gate))
    return 0;

  return gate;
}

/*
 * object *query_gates()
 * Return a single-element array for compatibility, or empty when none exist.
 */
object *query_gates() {
  if (!objectp(gate))
    return ({ });

  return ({ gate });
}

/* ------------------------------------------------------------ */
/* Gate actions
 * ------------------------------------------------------------ */

string *query_link_verbs(object actor, string endpoint_id) {
  return ({ });
}

int perform_link_action(object actor, string verb, string args, string endpoint_id) {
  return 0;
}

mapping _build_action_groups(object actor, string endpoint_id) {
  mapping groups;
  int endpoint_idx;
  int side;
  string name;
  string name_key;
  string *verbs;
  string verb;
  string v;
  int i;

  groups = ([ ]);

  if (!objectp(actor))
    return groups;

  endpoint_idx = endpoint_index(endpoint_id);

  if (endpoint_idx < 0)
    return groups;

  verbs = query_link_verbs(actor, endpoint_id);

  if (pointerp(verbs)) {
    for (i = 0; i < sizeof(verbs); i++) {
      verb = verbs[i];

      if (!stringp(verb) || trim(verb) == "")
        continue;

      verb = lower_case(trim(verb));

      if (!mapp(groups[verb]))
        groups[verb] = ([ ]);

      if (!pointerp(groups[verb]["__link__"]))
        groups[verb]["__link__"] = ({ });

      groups[verb]["__link__"] += ({ ([
        "gate" : 0,
        "side" : -1,
        "name" : "link"
      ]) });
    }
  }

  if (!objectp(gate))
    return groups;

  side = gate->side_facing_endpoint(endpoint_idx);

  if (function_exists("query_verbs", gate))
    verbs = gate->query_verbs(side, actor);
  else
    verbs = ({ });

  name = gate->query_name();

  if (!stringp(name) || name == "")
    name = "gate";

  name_key = lower_case(trim(name));

  if (name_key == "")
    name_key = "gate";

  if (pointerp(verbs)) {
    foreach (v in verbs) {
      verb = v;

      if (!stringp(verb) || trim(verb) == "")
        continue;

      verb = lower_case(trim(verb));

      if (!mapp(groups[verb]))
        groups[verb] = ([ ]);

      if (!pointerp(groups[verb][name_key]))
        groups[verb][name_key] = ({ });

      groups[verb][name_key] += ({ ([
        "gate" : gate,
        "side" : side,
        "name" : name
      ]) });
    }
  }

  return groups;
}

mapping _match_action_args(string args, mapping verb_actions) {
  mapping result;
  string args_clean;
  string args_lower;
  string name_key;
  string name_display;
  string remainder;
  int best_len;
  string candidate;
  int len;

  result = ([ "matched" : 0 ]);

  if (!mapp(verb_actions))
    return result;

  if (!stringp(args))
    args = "";

  args_clean = trim(args);

  if (args_clean == "") {
    if (pointerp(verb_actions["__link__"])) {
      result["matched"] = 1;
      result["name_key"] = "__link__";
      result["name"] = "link";
      result["remainder"] = "";
    }

    return result;
  }

  args_lower = lower_case(args_clean);
  best_len = -1;
  name_key = "";
  name_display = "";
  remainder = "";

  foreach (candidate in keys(verb_actions)) {
    if (!stringp(candidate) || candidate == "" || candidate == "__link__")
      continue;

    len = strlen(candidate);

    if (args_lower == candidate) {
      if (len > best_len) {
        name_key = candidate;
        name_display = verb_actions[candidate][0]["name"];
        remainder = "";
        best_len = len;
      }

      continue;
    }

    if (strlen(args_lower) > len &&
      args_lower[0..len-1] == candidate &&
      args_lower[len] == ' ') {
      if (len > best_len) {
        name_key = candidate;
        name_display = verb_actions[candidate][0]["name"];
        remainder = trim(args_clean[len..]);
        best_len = len;
      }
    }
  }

  if (best_len < 0)
    return result;

  result["matched"] = 1;
  result["name_key"] = name_key;
  result["name"] = name_display;
  result["remainder"] = remainder;

  return result;
}

mapping query_action_match(object actor, string verb, string args, string endpoint_id) {
  mapping actions;
  mapping verb_actions;
  mapping match;

  match = ([ "matched" : 0 ]);

  if (!objectp(actor))
    return match;

  if (!stringp(verb))
    return match;

  verb = lower_case(verb);

  actions = _build_action_groups(actor, endpoint_id);
  verb_actions = actions[verb];

  if (!mapp(verb_actions))
    return match;

  return _match_action_args(args, verb_actions);
}

int handle_action(object actor, string verb, string args, string endpoint_id) {
  mapping actions;
  mapping verb_actions;
  mapping match;
  mapping entry;
  mapping response;
  object gate;
  int side;
  int ok;
  string name;
  string remainder;

  if (!objectp(actor))
    return 0;

  if (!stringp(verb))
    return 0;

  verb = lower_case(verb);

  actions = _build_action_groups(actor, endpoint_id);
  verb_actions = actions[verb];

  if (!mapp(verb_actions))
    return 0;

  match = _match_action_args(args, verb_actions);

  if (!mapp(match) || !match["matched"])
    return 0;

  name = match["name"];
  remainder = match["remainder"];

  if (!stringp(name) || name == "")
    name = "gate";

  if (match["name_key"] == "__link__") {
    ok = perform_link_action(actor, verb, remainder, endpoint_id);

    return ok;
  }

  entry = verb_actions[match["name_key"]][0];

  if (!mapp(entry))
    return 0;

  gate = entry["gate"];
  side = entry["side"];

  if (!objectp(gate) || !function_exists("handle_action", gate))
    return 0;

  response = gate->handle_action(verb, actor, remainder, side);

  if (!mapp(response) || !response["handled"])
    return 0;

  if (stringp(response["message"]) && response["message"] != "")
    tell_object(actor, response["message"]);

  return 1;
}

/* ------------------------------------------------------------ */
/* Result helpers
 *
 * IMPORTANT: mutation and cost are orthogonal to outcome.
 * ------------------------------------------------------------ */

/*
 * mapping build_result(int outcome, string message, string redirect, int cost,
 *   mixed mutations)
 * Assemble a standardized link result mapping from outcome data.
 */
mapping build_result(
  int outcome, string message, string redirect,
  int cost, mixed mutations
) {
  mapping result;

  result = ([]);
  result[LINK_RESULT_OUTCOME] = outcome;

  if (stringp(message) && message != "")
    result[LINK_RESULT_MESSAGE] = message;

  if (stringp(redirect) && redirect != "")
    result[LINK_RESULT_REDIRECT] = redirect;

  if (!undefinedp(cost) && intp(cost) && cost > 0)
    result[LINK_RESULT_COST] = cost;

  if (!undefinedp(mutations) && (pointerp(mutations) || mapp(mutations)))
    result[LINK_RESULT_MUTATIONS] = mutations;

  return result;
}

/*
 * mapping allow_result()
 * Return a baseline allow result with no message, cost, or mutations.
 */
mapping allow_result() {
  return build_result(LINK_OUTCOME_ALLOW, "", "", 0, ({ }));
}

/*
 * mapping deny_result(string message, int cost, mixed mutations)
 * Return a denial result with optional message, cost, and mutations.
 */
mapping deny_result(string message, int cost, mixed mutations) {
  return build_result(LINK_OUTCOME_DENY, message, "", cost, mutations);
}

/*
 * int is_allowed_result(mapping result)
 * Report whether the result outcome represents an allowed traversal.
 */
int is_allowed_result(mapping result) {
  int outcome;

  if (!mapp(result))
    return 0;

  outcome = result[LINK_RESULT_OUTCOME];

  return (
    outcome == LINK_OUTCOME_ALLOW ||
    outcome == LINK_OUTCOME_ALLOW_REVERSE ||
    outcome == LINK_OUTCOME_ALLOW_REDIRECT
  );
}

/*
 * mapping merge_side_effects(mapping dst, mapping src)
 * Merge cost and mutations from src into dst, returning the updated mapping.
 */
mapping merge_side_effects(mapping dst, mapping src) {
  int c1, c2;
  mixed m1, m2;

  if (!mapp(dst)) dst = ([]);

  if (!mapp(src)) return dst;

  c1 = dst[LINK_RESULT_COST];
  c2 = src[LINK_RESULT_COST];

  if (!intp(c1)) c1 = 0;

  if (!intp(c2)) c2 = 0;

  if (c2 > 0) dst[LINK_RESULT_COST] = c1 + c2;

  m1 = dst[LINK_RESULT_MUTATIONS];
  m2 = src[LINK_RESULT_MUTATIONS];

  if (pointerp(m2) && sizeof(m2)) {
    if (!pointerp(m1)) m1 = ({ });

    dst[LINK_RESULT_MUTATIONS] = m1 + m2;
  } else if (mapp(m2) && sizeof(m2)) {
    /* if you prefer mapping effects, merge shallowly */
    if (!mapp(m1)) m1 = ([]);

    dst[LINK_RESULT_MUTATIONS] = m1 + m2;
  }

  return dst;
}

/* ------------------------------------------------------------ */
/* Link and gate traversal
 * ------------------------------------------------------------ */

/*
 * mapping check_link(object actor, string origin_id, string destination_id)
 * Hook for link-level traversal rules. Default allows passage.
 */
mapping check_link(object actor, string origin_id, string destination_id) {
  return allow_result();
}

/*
 * mapping check_gates(object actor, string origin_id, string destination_id)
 * Query the single gate, accumulating costs/mutations and returning a result.
 */
mapping check_gates(object actor, string origin_id, string destination_id) {
  int origin_idx;
  mapping agg, step;
  int gate_side;

  agg = allow_result();

  if (!objectp(actor))
    return deny_result("Nothing may pass.", 0, ({ }));

  origin_idx = endpoint_index(origin_id);

  if (origin_idx < 0)
    return deny_result("The link refuses to align.", 0, ({ }));

  if (!objectp(gate))
    return agg;

  gate_side = gate->side_facing_endpoint(origin_idx);
  step = gate->attempt_pass(actor, gate_side);

  if (mapp(step))
    agg = merge_side_effects(
      agg, ([
        LINK_RESULT_COST    : step["cost"],
        LINK_RESULT_MUTATIONS : step["effects"]
      ])
    );

  if (!mapp(step) || !step["allow"])
    return deny_result(
      step && step["message"]
        ? step["message"]
        : "Something blocks your way.",
      agg[LINK_RESULT_COST],
      agg[LINK_RESULT_MUTATIONS]
    );

  return agg;
} // mapping check_gates(object actor, string origin_id, string destination_id)

/* ------------------------------------------------------------ */
/* Room hooks (agency belongs to room/actors)
 * ------------------------------------------------------------ */

/*
 * mapping can_exit(object actor, object origin)
 * Hook for origin-side vetoes; returns an allow result by default.
 */
mapping can_exit(object actor, object origin) {
  /* Hook for future: origin->link_can_exit(actor, link) */
  return allow_result();
}

/*
 * mapping can_enter(object actor, object destination)
 * Query destination hook for pre-entry allowance, defaulting to allow.
 */
mapping can_enter(object actor, object destination) {
  mapping result;
  int outcome;

  if (objectp(destination) && function_exists("link_can_enter", destination)) {
    result = destination->link_can_enter(actor, this_object());

    if (mapp(result)) {
      outcome = result[LINK_RESULT_OUTCOME];

      if (undefinedp(outcome))
        return allow_result();

      return result;
    }
  }

  return allow_result();
}

/*
 * void on_exit(object actor, object origin, object destination)
 * Post-exit hook for origin-side reactions; does not return a value.
 */
void on_exit(object actor, object origin, object destination) {
  return;
}

/*
 * mapping on_enter(object actor, object origin, object destination)
 * Post-entry hook for destination reactions, returning an updated result.
 */
mapping on_enter(object actor, object origin, object destination) {
  mapping result;
  int outcome;

  if (objectp(destination) && function_exists("link_on_enter", destination)) {
    result = destination->link_on_enter(actor, origin, this_object());

    if (mapp(result)) {
      outcome = result[LINK_RESULT_OUTCOME];

      if (undefinedp(outcome))
        return allow_result();

      return result;
    }
  }

  return allow_result();
}

/* ------------------------------------------------------------ */
/* Lazy resolution helper
 * ------------------------------------------------------------ */

/*
 * object resolve_destination(string destination_id)
 * Find or load the destination object for the given id.
 */
object resolve_destination(string destination_id) {
  object env;

  if (!stringp(destination_id) || destination_id == "")
    return 0;

  env = find_object(destination_id);

  if (!objectp(env))
    env = load_object(destination_id);

  return env;
}

/****************************************************************************
 *
 * Ownership & Narration Rules
 * ---------------------------
 * Links own topology (gate, directionality, traversal cost).
 * Gates narrate topology-level interactions (blocked passage, etc.).
 *
 * Rooms and actors own local state and agency (guards, hazards).
 * Room/actor hooks may narrate and may request REVERSE/REDIRECT outcomes.
 *
 ****************************************************************************/

/*
 * mapping traverse(object actor, object origin)
 * Orchestrate traversal across gate and room hooks, returning the outcome.
 */
mapping traverse(object actor, object origin) {
  string origin_id, destination_id;
  object destination;
  mapping link_result, gate_result, exit_result, enter_result, enter_hook_result;
  int moved;

  if (!objectp(actor) || !objectp(origin))
    return deny_result("The link refuses to open.", 0, ({ }));

  origin_id = base_name(origin);
  destination_id = other_endpoint(origin_id);

  if (destination_id == "")
    return deny_result("The link does not reach anywhere.", 0, ({ }));

  if (!allows_path(origin_id, destination_id))
    return deny_result("The link does not run that way.", 0, ({ }));

  /* 1) Link-level traversal rules */
  link_result = check_link(actor, origin_id, destination_id);

  if (!is_allowed_result(link_result))
    return link_result;

  /* 2) Gate (topology) — no destination loading */
  gate_result = check_gates(actor, origin_id, destination_id);
  gate_result = merge_side_effects(gate_result, link_result);

  if (!is_allowed_result(gate_result))
    return gate_result;

  /* 3) Origin veto (optional, typically actor/room state) */
  exit_result = can_exit(actor, origin);
  exit_result = merge_side_effects(exit_result, gate_result);

  if (!is_allowed_result(exit_result))
    return exit_result;

  /* 4) Lazy-load destination only after gate+exit pass */
  destination = resolve_destination(destination_id);

  if (!objectp(destination))
    return deny_result(
      "The way opens into nothing.",
      exit_result[LINK_RESULT_COST],
      exit_result[LINK_RESULT_MUTATIONS]
    );

  /* 5) Destination veto (pre-entry) */
  enter_result = can_enter(actor, destination);
  enter_result = merge_side_effects(enter_result, exit_result);

  if (!is_allowed_result(enter_result))
    return enter_result;

  /* 6) Move */
  on_exit(actor, origin, destination);

  moved = actor->move(destination_id);

  if (!moved)
    return deny_result(
      "You cannot move that way.",
      enter_result[LINK_RESULT_COST],
      enter_result[LINK_RESULT_MUTATIONS]
    );

  /* 7) Post-entry reaction (room/actor agency) */
  enter_hook_result = on_enter(actor, origin, destination);
  enter_hook_result = merge_side_effects(enter_hook_result, enter_result);

  /* Handle REVERSE and REDIRECT spatially; preserve accumulated effects/cost */
  if (enter_hook_result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REVERSE) {
    actor->move(origin_id);

    show_actor_location(actor);

    return enter_hook_result;
  }

  if (enter_hook_result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REDIRECT) {
    string redirect;

    enter_hook_result[LINK_RESULT_INTERMEDIATE] = destination;
    redirect = enter_hook_result[LINK_RESULT_REDIRECT];

    if (stringp(redirect) && redirect != "")
      actor->move(redirect);

    show_actor_location(actor);

    return enter_hook_result;
  }

  show_actor_location(actor);

  return enter_hook_result;
} // mapping traverse(object actor, object origin)
