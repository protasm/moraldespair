inherit "/core/object";

#include <link.h>

string endpoint_a;
string endpoint_b;
mapping endpoint_labels;
mapping endpoint_gates;
mapping allowed_paths;

void create() {
  ::create();

  endpoint_a = "";
  endpoint_b = "";
  endpoint_labels = ([]);
  endpoint_gates = ([]);
  allowed_paths = ([]);

  return;
}

void set_endpoints(string first, string second) {
  if (!stringp(first) || !stringp(second))
    return;

  if (endpoint_a != "" || endpoint_b != "")
    return;

  endpoint_a = first;
  endpoint_b = second;

  allowed_paths = ([
    endpoint_a : endpoint_b,
    endpoint_b : endpoint_a
  ]);
}

string query_endpoint_a() {
  return endpoint_a;
}

string query_endpoint_b() {
  return endpoint_b;
}

int is_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return 0;

  if (endpoint == endpoint_a)
    return 1;

  if (endpoint == endpoint_b)
    return 1;

  return 0;
}

string other_endpoint(string endpoint) {
  if (!stringp(endpoint))
    return "";

  if (endpoint == endpoint_a)
    return endpoint_b;

  if (endpoint == endpoint_b)
    return endpoint_a;

  return "";
}

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

  allowed_paths = ([
    from_endpoint : to_endpoint
  ]);
}

int allows_path(string origin_id, string destination_id) {
  if (!stringp(origin_id) || !stringp(destination_id))
    return 0;

  if (allowed_paths[origin_id] == destination_id)
    return 1;

  return 0;
}

void add_gate(string endpoint, object gate) {
  object *gates;

  if (!stringp(endpoint))
    return;

  if (!objectp(gate))
    return;

  gates = endpoint_gates[endpoint];

  if (!pointerp(gates))
    gates = ({ });

  gates += ({ gate });
  endpoint_gates[endpoint] = gates;

  gate->set_link(this_object());
  gate->set_endpoint(endpoint);
}

object *query_gates(string endpoint) {
  object *gates;

  if (!stringp(endpoint))
    return ({ });

  gates = endpoint_gates[endpoint];

  if (!pointerp(gates))
    return ({ });

  return gates;
}

mapping build_result(int outcome, string message, string redirect,
                     mapping mutations) {
  mapping result;

  result = ([]);
  result[LINK_RESULT_OUTCOME] = outcome;

  if (stringp(message) && message != "")
    result[LINK_RESULT_MESSAGE] = message;

  if (stringp(redirect) && redirect != "")
    result[LINK_RESULT_REDIRECT] = redirect;

  if (mapp(mutations))
    result[LINK_RESULT_MUTATIONS] = mutations;

  return result;
}

mapping allow_result() {
  return build_result(LINK_OUTCOME_ALLOW, "", "", 0);
}

mapping deny_result(string message) {
  return build_result(LINK_OUTCOME_DENY, message, "", 0);
}

int is_allowed_result(mapping result) {
  int outcome;

  if (!mapp(result))
    return 0;

  outcome = result[LINK_RESULT_OUTCOME];

  if (outcome == LINK_OUTCOME_ALLOW)
    return 1;

  if (outcome == LINK_OUTCOME_ALLOW_REVERSE)
    return 1;

  if (outcome == LINK_OUTCOME_ALLOW_REDIRECT)
    return 1;

  if (outcome == LINK_OUTCOME_ALLOW_MUTATE)
    return 1;

  return 0;
}

mapping check_gates(object actor, string origin_id, string destination_id) {
  object *gates;
  int i;

  gates = query_gates(origin_id);

  for (i = 0; i < sizeof(gates); i++) {
    if (!objectp(gates[i]))
      continue;

    if (gates[i]->blocks_traversal(actor, origin_id, destination_id)) {
      return deny_result(
        gates[i]->blocked_message(actor, origin_id, destination_id)
      );
    }
  }

  gates = query_gates(destination_id);

  for (i = 0; i < sizeof(gates); i++) {
    if (!objectp(gates[i]))
      continue;

    if (gates[i]->blocks_traversal(actor, origin_id, destination_id)) {
      return deny_result(
        gates[i]->blocked_message(actor, origin_id, destination_id)
      );
    }
  }

  return allow_result();
}

mapping can_exit(object actor, object origin) {
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

/****************************************************************************
 *
 * Ownership & Narration Rules
 * ---------------------------
 * Links own connection state (gates, barriers, and topology). Rooms and
 * actors own local state and agency. Links may narrate link-owned outcomes
 * such as blocked passages or directional flavor. Rooms must not narrate
 * link-owned barriers, and links must not impersonate room-owned actors.
 *
 ****************************************************************************/

mapping traverse(object actor, object origin) {
  string origin_id, destination_id;
  object destination;
  mapping result;
  int moved;

  if (!objectp(actor) || !objectp(origin))
    return deny_result("The link refuses to open.");

  origin_id = base_name(origin);
  destination_id = other_endpoint(origin_id);

  if (destination_id == "")
    return deny_result("The link does not reach anywhere.");

  if (!allows_path(origin_id, destination_id))
    return deny_result("The link does not run that way.");

  result = check_gates(actor, origin_id, destination_id);

  if (!is_allowed_result(result))
    return result;

  result = can_exit(actor, origin);

  if (!is_allowed_result(result))
    return result;

  destination = load_object(destination_id);

  if (!objectp(destination))
    return deny_result("The way opens into nothing.");

  result = can_enter(actor, destination);

  if (!is_allowed_result(result))
    return result;

  on_exit(actor, origin, destination);

  moved = actor->move(destination_id);

  if (!moved)
    return deny_result("You cannot move that way.");

  result = on_enter(actor, origin, destination);

  if (result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REVERSE) {
    actor->move(origin_id);

    return result;
  }

  if (result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_REDIRECT) {
    string redirect;

    redirect = result[LINK_RESULT_REDIRECT];

    if (stringp(redirect))
      actor->move(redirect);

    return result;
  }

  if (result[LINK_RESULT_OUTCOME] == LINK_OUTCOME_ALLOW_MUTATE) {
    return result;
  }

  return result;
}
