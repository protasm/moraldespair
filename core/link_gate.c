/*
 * /core/link_gate.c
 *
 * A Gate is a structural barrier that lives on a Link.
 * It represents something encountered while traversing the space
 * between two environments (e.g. doors, bars, seals, rubble).
 *
 * A Gate has two sides, each facing one Link endpoint.
 * Side behavior may differ depending on perspective.
 *
 * Gates do NOT move players.
 * Gates do NOT know about rooms directly.
 * Gates are evaluated during Link traversal.
 */

inherit "/std/object";

#define SIDE_A 0
#define SIDE_B 1

/* Side state */
mapping side_state_a;
mapping side_state_b;

/* Optional metadata */
string gate_name;

/* Cost modifier */
int base_cost;

/* ------------------------------------------------------------ */

void create() {
  ::create();

  gate_name = "gate";
  base_cost = 0;

  side_state_a = ([
    "open"      : 1,
    "locked"    : 0,
    "lock_id"   : 0,
    "examine"   : 0,
    "block_msg" : "Something blocks your way.",
  ]);

  side_state_b = copy(side_state_a);
}

/* ------------------------------------------------------------ */
/* Utility */
/* ------------------------------------------------------------ */

mapping side_state(int side) {
  return side == SIDE_A ? side_state_a : side_state_b;
}

int opposite_side(int side) {
  return side == SIDE_A ? SIDE_B : SIDE_A;
}

/*
 * Translate an endpoint perspective into a gate side.
 * The Link is responsible for calling this correctly.
 */
int side_facing_endpoint(int endpoint_index) {
  return endpoint_index == SIDE_A ? SIDE_A : SIDE_B;
}

/* ------------------------------------------------------------ */
/* Configuration */
/* ------------------------------------------------------------ */

void set_name(string name) {
  gate_name = name;
}

string query_name() {
  return gate_name;
}

void set_base_cost(int cost) {
  base_cost = cost;
}

int query_base_cost() {
  return base_cost;
}

/* ------------------------------------------------------------ */
/* Side configuration helpers */
/* ------------------------------------------------------------ */

void set_open(int side, int open) {
  side_state(side)["open"] = open;
}

int is_open(int side) {
  return side_state(side)["open"];
}

void set_locked(int side, int locked) {
  side_state(side)["locked"] = locked;
}

int is_locked(int side) {
  return side_state(side)["locked"];
}

void set_lock_id(int side, mixed id) {
  side_state(side)["lock_id"] = id;
}

mixed query_lock_id(int side) {
  return side_state(side)["lock_id"];
}

void set_block_message(int side, string msg) {
  side_state(side)["block_msg"] = msg;
}

string query_block_message(int side) {
  return side_state(side)["block_msg"];
}

/* ------------------------------------------------------------ */
/* Traversal interface */
/* ------------------------------------------------------------ */

/*
 * Can the actor pass through this gate from this side?
 * Return a mapping describing the result.
 *
 * Expected keys:
 *   allow   : int (1 or 0)
 *   cost    : int (>= 0)
 *   effects : array (optional)
 *   message : string (optional, actor-facing)
 */
mapping attempt_pass(object actor, int side) {
  mapping state;

  state = side_state(side);

  if (!state["open"]) {
    return ([
      "allow"   : 0,
      "cost"    : base_cost,
      "effects" : ({ }),
      "message" : state["block_msg"],
    ]);
  }

  if (state["locked"]) {
    return ([
      "allow"   : 0,
      "cost"    : base_cost,
      "effects" : ({ }),
      "message" : "It is locked.",
    ]);
  }

  return ([
    "allow"   : 1,
    "cost"    : base_cost,
    "effects" : ({ }),
  ]);
}

/* ------------------------------------------------------------ */
/* Interaction hooks (optional, future-facing) */
/* ------------------------------------------------------------ */

/*
 * Called when an actor examines this gate from a given side.
 */
string examine(int side) {
  if (side_state(side)["examine"])
    return side_state(side)["examine"];

  return "It appears to be " + gate_name + ".";
}

/*
 * Attempt to unlock from a given side.
 * The caller (command system) handles key checks.
 */
int unlock(int side, mixed key_id) {
  if (!side_state(side)["locked"])
    return 0;

  if (side_state(side)["lock_id"] &&
      side_state(side)["lock_id"] != key_id)
    return 0;

  side_state(side)["locked"] = 0;
  return 1;
}

/*
 * Attempt to open from a given side.
 */
int open(int side) {
  if (side_state(side)["locked"])
    return 0;

  side_state(side)["open"] = 1;
  return 1;
}

/*
 * Attempt to close from a given side.
 */
int close(int side) {
  side_state(side)["open"] = 0;
  return 1;
}

