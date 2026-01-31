inherit "/core/object";

#include <link.h>

/*
 * Link: transient "between-space" connecting two endpoints.
 *
 * - Endpoints are strings (paths/IDs), resolved lazily.
 * - Gates are ordered between endpoint A and endpoint B.
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

/* Ordered list of gates from A -> B */
object *gates;

/* Optional explicit directionality shortcut (you may later rely purely on gates) */
mapping allowed_paths; /* origin_id -> dest_id (if present); empty means bidirectional */

/* ------------------------------------------------------------ */

void create() {
  ::create();

  endpoint_a = "";
  endpoint_b = "";

  endpoint_labels = ([]);
  gates = ({ });

  /* Default: bidirectional */
  allowed_paths = ([]);

  return;
}

/* ------------------------------------------------------------ */
/* Endpoints */
/* ------------------------------------------------------------ */

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

string query_endpoint_a() { return endpoint_a; }
string query_endpoint_b() { return endpoint_b; }

int is_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return 0;

  return (endpoint == endpoint_a || endpoint == endpoint_b);
}

string other_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return "";

  if (endpoint == endpoint_a) return endpoint_b;
  if (endpoint == endpoint_b) return endpoint_a;
  return "";
}

/*
 * Return 0 if endpoint is not A/B.
 * Return SIDE index expected by /core/gate: 0 for A, 1 for B.
 */
int endpoint_index(string endpoint) {
  if (endpoint == endpoint_a) return 0;
  if (endpoint == endpoint_b) return 1;
  return -1;
}

/* ------------------------------------------------------------ */
/* Labels (affordance only) */
/* ------------------------------------------------------------ */

void set_direction_label(string endpoint, string label) {
  if (!stringp(endpoint) || !stringp(label))
    return;

  endpoint_labels[endpoint] = label;
}

string query_direction_label(string endpoint) {
  if (!stringp(endpoint))
    return "";

  return endpoint_labels[endpoint];
}

/* ------------------------------------------------------------ */
/* Optional explicit directionality (may later be removed)
 * ------------------------------------------------------------ */

void set_bidirectional() {
  if (endpoint_a == "" || endpoint_b == "")
    return;

  allowed_paths = ([
    endpoint_a : endpoint_b,
    endpoint_b : endpoint_a
  ]);
}

void set_one_way(string from_endpoint, string to_endpoint) {
  if (!stringp(from_endpoint) || !stringp(to_endpoint))
    return;

  allowed_paths = ([ from_endpoint : to_endpoint ]);
}

int allows_path(string origin_id, string destination_id) {
  /* If allowed_paths is not set, default to bidirectional */
  if (!mapp(allowed_paths) || !sizeof(allowed_paths))
    return (other_endpoint(origin_id) == destination_id);

  return (allowed_paths[origin_id] == destination_id);
}

/* ------------------------------------------------------------ */
/* Gates (ordered A -> B)
 * ------------------------------------------------------------ */

void add_gate(object gate) {
  if (!objectp(gate))
    return;

  gates += ({ gate });

  /* Optional: if your gate objects want a backref, you can add set_link() later */
  if (function_exists("set_link", gate))
    gate->set_link(this_object());
}

object *query_gates() {
  if (!pointerp(gates))
    return ({ });
  return gates;
}

/* ------------------------------------------------------------ */
/* Result helpers
 *
 * IMPORTANT: mutation/effects and cost are orthogonal to outcome.
 * ------------------------------------------------------------ */

mapping build_result(int outcome, string message, string redirect,
                     int cost, mixed effects) {
  mapping result;

  result = ([]);
  result[LINK_RESULT_OUTCOME] = outcome;

  if (stringp(message) && message != "")
    result[LINK_RESULT_MESSAGE] = message;

  if (stringp(redirect) && redirect != "")
    result[LINK_RESULT_REDIRECT] = redirect;

  if (!undefinedp(cost) && intp(cost) && cost > 0)
    result[LINK_RESULT_COST] = cost;

  if (!undefinedp(effects) && (pointerp(effects) || mapp(effects)))
    result[LINK_RESULT_EFFECTS] = effects;

  return result;
}

mapping allow_result() {
  return build_result(LINK_OUTCOME_ALLOW, "", "", 0, ({ }));
}

mapping deny_result(string message, int cost, mixed effects) {
  return build_result(LINK_OUTCOME_DENY, message, "", cost, effects);
}

int is_allowed_result(mapping result) {
  int outcome;

  if (!mapp(result))
    return 0;

  outcome = result[LINK_RESULT_OUTCOME];

  return (outcome == LINK_OUTCOME_ALLOW ||
          outcome == LINK_OUTCOME_ALLOW_REVERSE ||
          outcome == LINK_OUTCOME_ALLOW_REDIRECT);
}

/*
 * Merge cost/effects from src into dst (orthogonal accumulation).
 */
mapping merge_side_effects(mapping dst, mapping src) {
  int c1, c2;
  mixed e1, e2;

  if (!mapp(dst)) dst = ([]);
  if (!mapp(src)) return dst;

  c1 = dst[LINK_RESULT_COST];
  c2 = src[LINK_RESULT_COST];

  if (!intp(c1)) c1 = 0;
  if (!intp(c2)) c2 = 0;
  if (c2 > 0) dst[LINK_RESULT_COST] = c1 + c2;

  e1 = dst[LINK_RESULT_EFFECTS];
  e2 = src[LINK_RESULT_EFFECTS];

  if (pointerp(e2) && sizeof(e2)) {
    if (!pointerp(e1)) e1 = ({ });
    dst[LINK_RESULT_EFFECTS] = e1 + e2;
  } else if (mapp(e2) && sizeof(e2)) {
    /* if you prefer mapping effects, merge shallowly */
    if (!mapp(e1)) e1 = ([]);
    dst[LINK_RESULT_EFFECTS] = e1 + e2;
  }

  return dst;
}

/* ------------------------------------------------------------ */
/* Gate traversal (ordered)
 * ------------------------------------------------------------ */

/*
 * Evaluate gates sequentially. The gate API we drafted:
 *   mapping attempt_pass(object actor, int side)
 * where side is 0 for A-facing, 1 for B-facing (gate.c internal)
 */
mapping check_gates(object actor, string origin_id, string destination_id) {
  object *gs;
  int origin_idx, i;
  int dir_ab; /* 1 if moving A->B, 0 if moving B->A */
  mapping agg, step;
  object gate;
  int gate_side;

  agg = allow_result();

  if (!objectp(actor))
    return deny_result("Nothing may pass.", 0, ({ }));

  origin_idx = endpoint_index(origin_id);
  if (origin_idx < 0)
    return deny_result("The link refuses to align.", 0, ({ }));

  dir_ab = (origin_id == endpoint_a); /* moving from A to B if origin is A */

  gs = query_gates();
  if (!sizeof(gs))
    return agg;

  if (dir_ab) {
    for (i = 0; i < sizeof(gs); i++) {
      gate = gs[i];
      if (!objectp(gate))
        continue;

      gate_side = gate->side_facing_endpoint(0); /* facing endpoint A */
      step = gate->attempt_pass(actor, gate_side);

      /* accumulate cost/effects even if denied */
      if (mapp(step))
        agg = merge_side_effects(agg, ([
          LINK_RESULT_COST    : step["cost"],
          LINK_RESULT_EFFECTS : step["effects"]
        ]));

      if (!mapp(step) || !step["allow"]) {
        return deny_result(step && step["message"] ? step["message"]
                                                  : "Something blocks your way.",
                           agg[LINK_RESULT_COST],
                           agg[LINK_RESULT_EFFECTS]);
      }
    }
  } else {
    /* moving from B to A: traverse gates in reverse, using B-facing side */
    for (i = sizeof(gs) - 1; i >= 0; i--) {
      gate = gs[i];
      if (!objectp(gate))
        continue;

      gate_side = gate->side_facing_endpoint(1); /* facing endpoint B */
      step = gate->attempt_pass(actor, gate_side);

      if (mapp(step))
        agg = merge_side_effects(agg, ([
          LINK_RESULT_COST    : step["cost"],
          LINK_RESULT_EFFECTS : step["effects"]
        ]));

      if (!mapp(step) || !step["allow"]) {
        return deny_result(step && step["message"] ? step["message"]
                                                  : "Something blocks your way.",
                           agg[LINK_RESULT_COST],
                           agg[LINK_RESULT_EFFECTS]);
      }
    }
  }

  return agg;
}

/* ------------------------------------------------------------ */
/* Room hooks (agency belongs to room/actors)
 * ------------------------------------------------------------ */

mapping can_exit(object actor, object origin) {
  /* Hook for future: origin->link_can_exit(actor, link) */
  return allow_result();
}

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

void on_exit(object actor, object origin, object destination) {
  return;
}

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
 * Links own topology (ordered gates, directionality, traversal cost).
 * Gates narrate topology-level interactions (blocked passage, etc.).
 *
 * Rooms and actors own local state and agency (guards, hazards).
 * Room/actor hooks may narrate and may request REVERSE/REDIRECT outcomes.
 *
 ****************************************************************************/

mapping traverse(object actor, object origin) {
  string origin_id, destination_id;
  object destination;
  mapping result, gate_result, exit_result, enter_result, enter_hook_result;
  int moved;

  if (!objectp(actor) || !objectp(origin))
    return deny_result("The link refuses to open.", 0, ({ }));

  origin_id = base_name(origin);
  destination_id = other_endpoint(origin_id);

  if (destination_id == "")
    return deny_result("The link does not reach anywhere.", 0, ({ }));

  if (!allows_path(origin_id, destination_id))
    return deny_result("The link does not run that way.", 0, ({ }));

  /* 1) Gates (topology) — no destination loading */
  gate_result = check_gates(actor, origin_id, destination_id);
  if (!is_allowed_result(gate_result))
    return gate_result;

  /* 2) Origin veto (optional, typically actor/room state) */
  exit_result = can_exit(actor, origin);
  exit_result = merge_side_effects(exit_result, gate_result);
  if (!is_allowed_result(exit_result))
    return exit_result;

  /* 3) Lazy-load destination only after gate+exit pass */
  destination = resolve_destination(destination_id);
  if (!objectp(destination))
    return deny_result("The way opens into nothing.", exit_result[LINK_RESULT_COST],
                       exit_result[LINK_RESULT_EFFECTS]);

  /* 4) Destination veto (pre-entry) */
  enter_result = can_enter(actor, destination);
  enter_result = merge_side_effects(enter_result, exit_result);
  if (!is_allowed_result(enter_result))
    return enter_result;

  /* 5) Move */
  on_exit(actor, origin, destination);

  moved = actor->move(destination_id);
  if (!moved)
    return deny_result("You cannot move that way.",
                       enter_result[LINK_RESULT_COST],
                       enter_result[LINK_RESULT_EFFECTS]);

  /* 6) Post-entry reaction (room/actor agency) */
  enter_hook_result = on_enter(actor, origin, destination);
  enter_hook_result = merge_side_effects(enter_hook_result, enter_result);

  /* Handle REVERSE and REDIRECT spatially; preserve accumulated effects/cost */
  if (enter_hook_result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REVERSE) {
    actor->move(origin_id);
    return enter_hook_result;
  }

  if (enter_hook_result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REDIRECT) {
    string redirect;

    enter_hook_result[LINK_RESULT_INTERMEDIATE] = destination;
    redirect = enter_hook_result[LINK_RESULT_REDIRECT];

    if (stringp(redirect) && redirect != "")
      actor->move(redirect);

    return enter_hook_result;
  }

  return enter_hook_result;
}

