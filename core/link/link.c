/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/link/link.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 *   - #include "/core/link/link.h"
 *   - #include <globals.h>
 */

inherit "/core/object/object";

#include "/core/link/link.h"
#include <globals.h>

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

string endpoint_a_id;
string endpoint_b_id;

/* Optional endpoint-specific direction labels (purely affordance/UI) */
mapping endpoint_labels; /* endpoint_path -> label string */
mapping link_meta;
mapping endpoint_appearances; /* endpoint_path -> description */
string default_appearance;

/* Optional gate between endpoints */
object link_gate;

/* Optional explicit directionality shortcut (you may later rely purely on gate) */
mapping allowed_paths; /* origin_id -> dest_id (if present); empty means bidirectional */

/* ------------------------------------------------------------ */

/*
 * void create()
 * Initialize link state with empty endpoints, labels, metadata, gate, and
 * default bidirectional paths.
 */
/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  endpoint_a_id = "";
  endpoint_b_id = "";

  endpoint_labels = ([]);
  link_meta = ([]);
  endpoint_appearances = ([]);
  default_appearance = "It seems possible to go that way.";
  link_gate = 0;

  /* Default: bidirectional */
  allowed_paths = ([]);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles show_actor_location for this object.
 * Parameters:
 *   - object actor
 * Approach:
 *   Validates inputs and executes explicit local logic for show_actor_location.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from show_actor_location.
 */
void show_actor_location(object actor) {
  if (!objectp(actor))
    return;

  if (!is_connected_avatar(actor))
    return;

  if (function_exists("show_location", actor))
    actor->show_location(0, 1);
}

/* Method Summary:
 * Purpose:
 *   Handles deliver_link_feedback for this object.
 * Parameters:
 *   - object actor, object room, string message, string verb
 * Approach:
 *   Routes gate/link response text through EXPERIENCE_D when available.
 * Side effects:
 *   Sends canonical actor-facing feedback events.
 * Returns:
 *   void result from deliver_link_feedback.
 */
void deliver_link_feedback(object actor, object room, string message, string verb) {
  if (!objectp(actor))
    return;

  if (!stringp(message) || message == "")
    return;

  EXPERIENCE_D->emit_link_action_feedback(actor, room, message, verb);

  return;
}

/* ------------------------------------------------------------ */
/* Endpoints */
/* ------------------------------------------------------------ */

/*
 * void set_endpoints(string first, string second)
 * Define the two endpoints once, and seed default bidirectional routing.
 */
/* Method Summary:
 * Purpose:
 *   Handles set_endpoints for this object.
 * Parameters:
 *   - string first, string second
 * Approach:
 *   Validates inputs and executes explicit local logic for set_endpoints.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_endpoints.
 */
void set_endpoints(string first, string second) {
  if (!stringp(first) || !stringp(second))
    return;

  if (endpoint_a_id != "" || endpoint_b_id != "")
    return;

  endpoint_a_id = first;
  endpoint_b_id = second;

  /* Default bidirectional unless explicitly constrained */
  allowed_paths = ([
    endpoint_a_id : endpoint_b_id,
    endpoint_b_id : endpoint_a_id
  ]);
}

/*
 * string endpoint_a()
 * Return the endpoint A id, or "" if it has not been set.
 */
/* Method Summary:
 * Purpose:
 *   Handles endpoint_a for this object.
 * Parameters:
 *   - ) { return endpoint_a_id; }
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_a.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_a.
 */
string endpoint_a() { return endpoint_a_id; }

/*
 * string endpoint_b()
 * Return the endpoint B id, or "" if it has not been set.
 */
/* Method Summary:
 * Purpose:
 *   Handles endpoint_b for this object.
 * Parameters:
 *   - ) { return endpoint_b_id; }
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_b.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_b.
 */
string endpoint_b() { return endpoint_b_id; }

/*
 * int is_endpoint(string endpoint)
 * Report whether the provided id matches either endpoint.
 */
/* Method Summary:
 * Purpose:
 *   Handles is_endpoint for this object.
 * Parameters:
 *   - string endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for is_endpoint.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_endpoint.
 */
int is_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return 0;

  return (endpoint == endpoint_a_id || endpoint == endpoint_b_id);
}

/*
 * string other_endpoint(string endpoint)
 * Return the opposite endpoint id, or "" if the input is not an endpoint.
 */
/* Method Summary:
 * Purpose:
 *   Handles other_endpoint for this object.
 * Parameters:
 *   - string endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for other_endpoint.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from other_endpoint.
 */
string other_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return "";

  if (endpoint == endpoint_a_id) return endpoint_b_id;

  if (endpoint == endpoint_b_id) return endpoint_a_id;

  return "";
}

/*
 * int endpoint_index(string endpoint)
 * Return the gate-facing side index (0 for A, 1 for B), or -1 if unknown.
 */
/* Method Summary:
 * Purpose:
 *   Handles endpoint_index for this object.
 * Parameters:
 *   - string endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_index.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from endpoint_index.
 */
int endpoint_index(string endpoint) {
  if (endpoint == endpoint_a_id) return 0;

  if (endpoint == endpoint_b_id) return 1;

  return -1;
}

/* ------------------------------------------------------------ */
/* Labels (affordance only) */
/* ------------------------------------------------------------ */

/*
 * void set_direction_label(string endpoint, string label)
 * Store a user-facing direction label for a specific endpoint id.
 */
/* Method Summary:
 * Purpose:
 *   Handles set_direction_label for this object.
 * Parameters:
 *   - string endpoint, string label
 * Approach:
 *   Validates inputs and executes explicit local logic for set_direction_label.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_direction_label.
 */
void set_direction_label(string endpoint, string label) {
  if (!stringp(endpoint) || !stringp(label))
    return;

  endpoint_labels[endpoint] = label;
}

/*
 * string direction_label(string endpoint)
 * Return the direction label for an endpoint, or "" when none is set.
 */
/* Method Summary:
 * Purpose:
 *   Handles direction_label for this object.
 * Parameters:
 *   - string endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for direction_label.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from direction_label.
 */
string direction_label(string endpoint) {
  if (!stringp(endpoint))
    return "";

  return endpoint_labels[endpoint];
}

/*
 * void set_dirs(mapping dirs)
 * Replace direction labels with a normalized string->string mapping.
 */
/* Method Summary:
 * Purpose:
 *   Handles set_dirs for this object.
 * Parameters:
 *   - mapping dirs
 * Approach:
 *   Validates inputs and executes explicit local logic for set_dirs.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_dirs.
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
 * mapping dirs()
 * Return the direction-label mapping, or an empty mapping when unset.
 */
/* Method Summary:
 * Purpose:
 *   Handles dirs for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for dirs.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from dirs.
 */
mapping dirs() {
  if (!mapp(endpoint_labels))
    return ([ ]);

  return endpoint_labels;
}

/* ------------------------------------------------------------ */
/* Appearance */
/* ------------------------------------------------------------ */

/* Method Summary:
 * Purpose:
 *   Handles set_appearance for this object.
 * Parameters:
 *   - string description
 * Approach:
 *   Validates inputs and executes explicit local logic for set_appearance.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_appearance.
 */
void set_appearance(string description) {
  if (!stringp(description))
    return;

  default_appearance = description;
}

/* Method Summary:
 * Purpose:
 *   Handles set_endpoint_appearance for this object.
 * Parameters:
 *   - string endpoint, string description
 * Approach:
 *   Validates inputs and executes explicit local logic for set_endpoint_appearance.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_endpoint_appearance.
 */
void set_endpoint_appearance(string endpoint, string description) {
  if (!stringp(endpoint) || !stringp(description))
    return;

  endpoint_appearances[endpoint] = description;
}

/* Method Summary:
 * Purpose:
 *   Handles set_appearances for this object.
 * Parameters:
 *   - mapping appearances
 * Approach:
 *   Validates inputs and executes explicit local logic for set_appearances.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_appearances.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles appearance for this object.
 * Parameters:
 *   - string endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for appearance.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from appearance.
 */
string appearance(string endpoint) {
  string description;

  description = "";

  if (stringp(endpoint) && mapp(endpoint_appearances))
    description = endpoint_appearances[endpoint];

  if (!stringp(description) || description == "")
    description = default_appearance;

  return description;
}

/* Method Summary:
 * Purpose:
 *   Handles gate_status_line for this object.
 * Parameters:
 *   - string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for gate_status_line.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from gate_status_line.
 */
string gate_status_line(string endpoint_id) {
  int endpoint_idx;
  int side;
  string name;
  string status;

  endpoint_idx = endpoint_index(endpoint_id);

  if (endpoint_idx < 0)
    return "";

  if (!objectp(link_gate))
    return "";

  side = link_gate->side_facing_endpoint(endpoint_idx);
  name = link_gate->name();

  if (!stringp(name) || name == "")
    name = "gate";

  status = "";

  if (function_exists("status", link_gate))
    status = link_gate->status(side);

  if (stringp(status))
    status = trim(status);

  if (stringp(status) && status != "")
    return "Visible that way: " + name + " [" + status + "].\n";

  return "Visible that way: " + name + ".\n";
}

/* Method Summary:
 * Purpose:
 *   Handles describe_from_endpoint for this object.
 * Parameters:
 *   - string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for describe_from_endpoint.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from describe_from_endpoint.
 */
string describe_from_endpoint(string endpoint_id) {
  string description;
  string gate_line;

  description = appearance(endpoint_id);

  if (!stringp(description) || description == "")
    description = default_appearance;

  if (description[<1] != '\n')
    description += "\n";

  gate_line = gate_status_line(endpoint_id);

  if (stringp(gate_line) && gate_line != "")
    description += gate_line;

  return description;
}

/*
 * void set_meta(string key, mixed value)
 * Store arbitrary metadata keyed by non-empty string.
 */
/* Method Summary:
 * Purpose:
 *   Handles set_meta for this object.
 * Parameters:
 *   - string key, mixed value
 * Approach:
 *   Validates inputs and executes explicit local logic for set_meta.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_meta.
 */
void set_meta(string key, mixed value) {
  if (!stringp(key) || key == "")
    return;

  if (!mapp(link_meta))
    link_meta = ([]);

  link_meta[key] = value;
}

/*
 * mixed meta(string key)
 * Return metadata for the given key, or 0 when missing.
 */
/* Method Summary:
 * Purpose:
 *   Handles meta for this object.
 * Parameters:
 *   - string key
 * Approach:
 *   Validates inputs and executes explicit local logic for meta.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mixed result from meta.
 */
mixed meta(string key) {
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
/* Method Summary:
 * Purpose:
 *   Handles set_bidirectional for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for set_bidirectional.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_bidirectional.
 */
void set_bidirectional() {
  if (endpoint_a_id == "" || endpoint_b_id == "")
    return;

  allowed_paths = ([
    endpoint_a_id : endpoint_b_id,
    endpoint_b_id : endpoint_a_id
  ]);
}

/*
 * void set_one_way(string from_endpoint, string to_endpoint)
 * Restrict travel to the specified direction only.
 */
/* Method Summary:
 * Purpose:
 *   Handles set_one_way for this object.
 * Parameters:
 *   - string from_endpoint, string to_endpoint
 * Approach:
 *   Validates inputs and executes explicit local logic for set_one_way.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_one_way.
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
/* Method Summary:
 * Purpose:
 *   Handles allows_path for this object.
 * Parameters:
 *   - string origin_id, string destination_id
 * Approach:
 *   Validates inputs and executes explicit local logic for allows_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from allows_path.
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
/* Method Summary:
 * Purpose:
 *   Handles add_gate for this object.
 * Parameters:
 *   - object gate_obj
 * Approach:
 *   Validates inputs and executes explicit local logic for add_gate.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from add_gate.
 */
void add_gate(object gate_obj) {
  if (!objectp(gate_obj))
    return;

  link_gate = gate_obj;

  /* Optional: if your gate objects want a backref, you can add set_link() later */
  if (function_exists("set_link", link_gate))
    link_gate->set_link(this_object());
}

/*
 * object gate()
 * Return the gate object, or 0 when none exists.
 */
/* Method Summary:
 * Purpose:
 *   Handles gate for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for gate.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from gate.
 */
object gate() {
  if (!objectp(link_gate))
    return 0;

  return link_gate;
}

/*
 * object *gates()
 * Return a single-element array for compatibility, or empty when none exist.
 */
/* Method Summary:
 * Purpose:
 *   Handles gates for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for gates.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from gates.
 */
object *gates() {
  if (!objectp(link_gate))
    return ({ });

  return ({ link_gate });
}

/* ------------------------------------------------------------ */
/* Gate actions
 * ------------------------------------------------------------ */

/* Method Summary:
 * Purpose:
 *   Handles link_verbs for this object.
 * Parameters:
 *   - object actor, string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for link_verbs.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from link_verbs.
 */
string *link_verbs(object actor, string endpoint_id) {
  return ({ });
}

/* Method Summary:
 * Purpose:
 *   Handles perform_link_action for this object.
 * Parameters:
 *   - object actor, string verb, string args, string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for perform_link_action.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from perform_link_action.
 */
int perform_link_action(object actor, string verb, string args, string endpoint_id) {
  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles _build_action_groups for this object.
 * Parameters:
 *   - object actor, string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for _build_action_groups.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from _build_action_groups.
 */
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

  verbs = link_verbs(actor, endpoint_id);

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

  if (!objectp(link_gate))
    return groups;

  side = link_gate->side_facing_endpoint(endpoint_idx);

  if (function_exists("verbs", link_gate))
    verbs = link_gate->verbs(side, actor);
  else
    verbs = ({ });

  name = link_gate->name();

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
        "gate" : link_gate,
        "side" : side,
        "name" : name
      ]) });
    }
  }

  return groups;
}

/* Method Summary:
 * Purpose:
 *   Handles _match_action_args for this object.
 * Parameters:
 *   - string args, mapping verb_actions
 * Approach:
 *   Validates inputs and executes explicit local logic for _match_action_args.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from _match_action_args.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles action_match for this object.
 * Parameters:
 *   - object actor, string verb, string args, string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for action_match.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from action_match.
 */
mapping action_match(object actor, string verb, string args, string endpoint_id) {
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

/* Method Summary:
 * Purpose:
 *   Handles handle_action for this object.
 * Parameters:
 *   - object actor, string verb, string args, string endpoint_id
 * Approach:
 *   Validates inputs and executes explicit local logic for handle_action.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from handle_action.
 */
int handle_action(object actor, string verb, string args, string endpoint_id) {
  mapping actions;
  mapping verb_actions;
  mapping match;
  mapping entry;
  mapping response;
  object gate;
  object room;
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

  if (stringp(response["message"]) && response["message"] != "") {
    room = environment(actor);
    deliver_link_feedback(actor, room, response["message"], verb);
  }

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
/* Method Summary:
 * Purpose:
 *   Handles build_result for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for build_result.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from build_result.
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
/* Method Summary:
 * Purpose:
 *   Handles allow_result for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for allow_result.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from allow_result.
 */
mapping allow_result() {
  return build_result(LINK_OUTCOME_ALLOW, "", "", 0, ({ }));
}

/*
 * mapping deny_result(string message, int cost, mixed mutations)
 * Return a denial result with optional message, cost, and mutations.
 */
/* Method Summary:
 * Purpose:
 *   Handles deny_result for this object.
 * Parameters:
 *   - string message, int cost, mixed mutations
 * Approach:
 *   Validates inputs and executes explicit local logic for deny_result.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from deny_result.
 */
mapping deny_result(string message, int cost, mixed mutations) {
  return build_result(LINK_OUTCOME_DENY, message, "", cost, mutations);
}

/*
 * int is_allowed_result(mapping result)
 * Report whether the result outcome represents an allowed traversal.
 */
/* Method Summary:
 * Purpose:
 *   Handles is_allowed_result for this object.
 * Parameters:
 *   - mapping result
 * Approach:
 *   Validates inputs and executes explicit local logic for is_allowed_result.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_allowed_result.
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
/* Method Summary:
 * Purpose:
 *   Handles merge_side_effects for this object.
 * Parameters:
 *   - mapping dst, mapping src
 * Approach:
 *   Validates inputs and executes explicit local logic for merge_side_effects.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from merge_side_effects.
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
/* Method Summary:
 * Purpose:
 *   Handles check_link for this object.
 * Parameters:
 *   - object actor, string origin_id, string destination_id
 * Approach:
 *   Validates inputs and executes explicit local logic for check_link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from check_link.
 */
mapping check_link(object actor, string origin_id, string destination_id) {
  return allow_result();
}

/*
 * mapping check_gates(object actor, string origin_id, string destination_id)
 * Query the single gate, accumulating costs/mutations and returning a result.
 */
/* Method Summary:
 * Purpose:
 *   Handles check_gates for this object.
 * Parameters:
 *   - object actor, string origin_id, string destination_id
 * Approach:
 *   Validates inputs and executes explicit local logic for check_gates.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from check_gates.
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

  if (!objectp(link_gate))
    return agg;

  gate_side = link_gate->side_facing_endpoint(origin_idx);
  step = link_gate->attempt_pass(actor, gate_side);

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
/* Method Summary:
 * Purpose:
 *   Handles can_exit for this object.
 * Parameters:
 *   - object actor, object origin
 * Approach:
 *   Validates inputs and executes explicit local logic for can_exit.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from can_exit.
 */
mapping can_exit(object actor, object origin) {
  /* Hook for future: origin->link_can_exit(actor, link) */
  return allow_result();
}

/*
 * mapping can_enter(object actor, object destination)
 * Query destination hook for pre-entry allowance, defaulting to allow.
 */
/* Method Summary:
 * Purpose:
 *   Handles can_enter for this object.
 * Parameters:
 *   - object actor, object destination
 * Approach:
 *   Validates inputs and executes explicit local logic for can_enter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from can_enter.
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
/* Method Summary:
 * Purpose:
 *   Handles on_exit for this object.
 * Parameters:
 *   - object actor, object origin, object destination
 * Approach:
 *   Validates inputs and executes explicit local logic for on_exit.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from on_exit.
 */
void on_exit(object actor, object origin, object destination) {
  return;
}

/*
 * mapping on_enter(object actor, object origin, object destination)
 * Post-entry hook for destination reactions, returning an updated result.
 */
/* Method Summary:
 * Purpose:
 *   Handles on_enter for this object.
 * Parameters:
 *   - object actor, object origin, object destination
 * Approach:
 *   Validates inputs and executes explicit local logic for on_enter.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from on_enter.
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
/* Method Summary:
 * Purpose:
 *   Handles resolve_destination for this object.
 * Parameters:
 *   - string destination_id
 * Approach:
 *   Validates inputs and executes explicit local logic for resolve_destination.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from resolve_destination.
 */
object resolve_destination(string destination_id) {
  object env;
  object room_data_daemon;
  mapping resolved_spec;
  string virtual_path;
  string custom_path;

  if (!stringp(destination_id) || destination_id == "")
    return 0;

  env = find_object(destination_id);

  if (!objectp(env))
    catch(env = load_object(destination_id));

  /*
   * Keep strict same-path resolution for virtual rooms if load_object() does
   * not dispatch on this driver for the requested absolute virtual id.
   */
  if (!objectp(env)) {
    room_data_daemon = find_object("/core/daemon/room_data_d");

    if (!objectp(room_data_daemon))
      room_data_daemon = load_object("/core/daemon/room_data_d");

    resolved_spec = 0;

    if (objectp(room_data_daemon)) {
      if (function_exists("resolve_room_request", room_data_daemon))
        resolved_spec = room_data_daemon->resolve_room_request(destination_id);

      if (!mapp(resolved_spec))
        resolved_spec = room_data_daemon->virtual_spec(destination_id);
    }

    if (mapp(resolved_spec)) {
      custom_path = resolved_spec["custom_path"];

      if (stringp(custom_path) && custom_path != "") {
        catch(env = load_object(custom_path));

        if (objectp(env))
          return env;
      }

      virtual_path = resolved_spec["path"];

      if (stringp(virtual_path) && virtual_path != "")
        catch(
          env = "/core/daemon/vroom_d"->compile_object(
            "vroom#" + virtual_path
          )
        );
    }
  }

  return env;
}

/* Method Summary:
 * Purpose:
 *   Handles show_resolution_debug for this object.
 * Parameters:
 *   - object actor, string text
 * Approach:
 *   Validates inputs and executes explicit local logic for show_resolution_debug.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from show_resolution_debug.
 */
void show_resolution_debug(object actor, string text) {
  string actor_name;
  string line;

  if (!stringp(text) || text == "")
    return;

  actor_name = "(no-actor)";

  if (objectp(actor))
    actor_name = file_name(actor);

  line = ctime(time()) + " link " + actor_name + " " + text + "\n";

  write_file("/log/virtual_room_debug", line);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles endpoint_id_for_room for this object.
 * Parameters:
 *   - object room
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoint_id_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoint_id_for_room.
 */
string endpoint_id_for_room(object room) {
  string endpoint_id;

  endpoint_id = "";

  if (!objectp(room))
    return endpoint_id;

  if (function_exists("link_endpoint_id", room))
    endpoint_id = room->link_endpoint_id();

  if (!stringp(endpoint_id) || endpoint_id == "")
    endpoint_id = base_name(room);

  return endpoint_id;
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
/* Method Summary:
 * Purpose:
 *   Handles traverse for this object.
 * Parameters:
 *   - object actor, object origin
 * Approach:
 *   Validates inputs and executes explicit local logic for traverse.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from traverse.
 */
mapping traverse(object actor, object origin) {
  string origin_id, destination_id;
  string resolved_name;
  string debug_message;
  object destination;
  object existing_destination;
  mixed destination_error, move_error;
  mapping link_result, gate_result, exit_result, enter_result, enter_hook_result;
  int custom_exists;
  int moved;

  if (!objectp(actor) || !objectp(origin))
    return deny_result("The link refuses to open.", 0, ({ }));

  origin_id = endpoint_id_for_room(origin);
  destination_id = other_endpoint(origin_id);

  if (destination_id == "")
    return deny_result("The link does not reach anywhere.", 0, ({ }));

  if (!allows_path(origin_id, destination_id))
    return deny_result("The link does not run that way.", 0, ({ }));

  /* 1) Link-level traversal rules */
  link_result = check_link(actor, origin_id, destination_id);

  if (!is_allowed_result(link_result)) {
    debug_message = link_result[LINK_RESULT_MESSAGE];

    if (!stringp(debug_message) || debug_message == "")
      debug_message = "(none)";

    show_resolution_debug(actor, "deny at check_link: " + debug_message);
    return link_result;
  }

  /* 2) Gate (topology) — no destination loading */
  gate_result = check_gates(actor, origin_id, destination_id);
  gate_result = merge_side_effects(gate_result, link_result);

  if (!is_allowed_result(gate_result)) {
    debug_message = gate_result[LINK_RESULT_MESSAGE];

    if (!stringp(debug_message) || debug_message == "")
      debug_message = "(none)";

    show_resolution_debug(actor, "deny at gate check: " + debug_message);
    return gate_result;
  }

  /* 3) Origin veto (optional, typically actor/room state) */
  exit_result = can_exit(actor, origin);
  exit_result = merge_side_effects(exit_result, gate_result);

  if (!is_allowed_result(exit_result)) {
    debug_message = exit_result[LINK_RESULT_MESSAGE];

    if (!stringp(debug_message) || debug_message == "")
      debug_message = "(none)";

    show_resolution_debug(actor, "deny at origin exit hook: " + debug_message);
    return exit_result;
  }

  /* 4) Lazy-load destination only after gate+exit pass */
  show_resolution_debug(
    actor,
    "resolving destination: from " + origin_id + " to " + destination_id
  );
  existing_destination = find_object(destination_id);
  custom_exists = (file_size(destination_id + ".c") > -1);

  if (objectp(existing_destination))
    show_resolution_debug(actor, "destination already loaded: " + base_name(existing_destination));
  else if (custom_exists)
    show_resolution_debug(actor, "loading custom room object: " + destination_id + ".c");
  else
    show_resolution_debug(actor, "custom room not found; attempting virtual room resolution");

  destination_error = catch(destination = resolve_destination(destination_id));

  if (destination_error) {
    show_resolution_debug(actor, "deny at destination resolve: " + destination_error);
    return deny_result(
      "The way shudders and fails to open.",
      exit_result[LINK_RESULT_COST],
      exit_result[LINK_RESULT_MUTATIONS]
    );
  }

  if (!objectp(destination)) {
    show_resolution_debug(actor, "deny at destination resolve: object not created");
    return deny_result(
      "The way opens into nothing.",
      exit_result[LINK_RESULT_COST],
      exit_result[LINK_RESULT_MUTATIONS]
    );
  }

  resolved_name = base_name(destination);
  show_resolution_debug(actor, "resolved destination object: " + resolved_name);

  /* 5) Destination veto (pre-entry) */
  enter_result = can_enter(actor, destination);
  enter_result = merge_side_effects(enter_result, exit_result);

  if (!is_allowed_result(enter_result)) {
    debug_message = enter_result[LINK_RESULT_MESSAGE];

    if (!stringp(debug_message) || debug_message == "")
      debug_message = "(none)";

    show_resolution_debug(actor, "deny at destination enter hook: " + debug_message);
    return enter_result;
  }

  /* 6) Move */
  on_exit(actor, origin, destination);

  move_error = catch(moved = actor->move(destination));
  if (move_error) {
    show_resolution_debug(actor, "deny at actor->move: " + move_error);
    return deny_result(
      "You cannot move that way.",
      enter_result[LINK_RESULT_COST],
      enter_result[LINK_RESULT_MUTATIONS]
    );
  }

  if (!moved) {
    show_resolution_debug(actor, "deny at actor->move: move returned false");
    return deny_result(
      "You cannot move that way.",
      enter_result[LINK_RESULT_COST],
      enter_result[LINK_RESULT_MUTATIONS]
    );
  }

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
