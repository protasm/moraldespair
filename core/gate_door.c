/*
 * /core/gate_door.c
 *
 * Concrete Gate subclass implementing door semantics.
 *
 * A door:
 *  - may open or close
 *  - may lock or unlock
 *  - may behave differently from each side
 *  - may allow passage in one or both directions
 *
 * This class models:
 *  - hinged doors
 *  - swinging doors
 *  - sliding doors
 *  - portcullises
 */

inherit "/core/gate";

/* ------------------------------------------------------------ */
/* Door state (per side)
 *
 * Each side may differ:
 *  - open / closed
 *  - locked / unlocked
 *  - lock_id
 *  - messages
 * ------------------------------------------------------------ */

#define SIDE_A 0
#define SIDE_B 1

void create() {
  ::create();

  set_name("door");

  /* Initialize default door state */
  side_state(SIDE_A)["open"]       = 0;
  side_state(SIDE_A)["locked"]     = 0;
  side_state(SIDE_A)["lock_id"]    = 0;
  side_state(SIDE_A)["block_msg"]  = "The door is closed.";

  side_state(SIDE_B)["open"]       = 0;
  side_state(SIDE_B)["locked"]     = 0;
  side_state(SIDE_B)["lock_id"]    = 0;
  side_state(SIDE_B)["block_msg"]  = "The door is closed.";
}

/* ------------------------------------------------------------ */
/* Capability declarations
 * ------------------------------------------------------------ */

int supports_opening() {
  return 1;
}

int supports_locking() {
  return 1;
}

/* ------------------------------------------------------------ */
/* Traversal logic
 * ------------------------------------------------------------ */

mapping attempt_pass(object actor, int side) {
  mapping state = side_state(side);

  if (!state["open"]) {
    return ([
      "allow"   : 0,
      "cost"    : query_base_cost(),
      "effects" : ({ }),
      "message" : state["block_msg"] || "The door is closed.",
    ]);
  }

  if (state["locked"]) {
    return ([
      "allow"   : 0,
      "cost"    : query_base_cost(),
      "effects" : ({ }),
      "message" : "The door is locked.",
    ]);
  }

  return ([
    "allow"   : 1,
    "cost"    : query_base_cost(),
    "effects" : ({ }),
  ]);
}

/* ------------------------------------------------------------ */
/* Door interaction verbs
 * ------------------------------------------------------------ */

int open(int side, object actor) {
  mapping state = side_state(side);

  if (state["open"])
    return 0;

  if (state["locked"])
    return 0;

  state["open"] = 1;
  side_state(opposite_side(side))["open"] = 1;

  return 1;
}

int close(int side, object actor) {
  mapping state = side_state(side);

  if (!state["open"])
    return 0;

  state["open"] = 0;
  side_state(opposite_side(side))["open"] = 0;

  return 1;
}

int lock(int side, object actor, mixed key_id) {
  mapping state = side_state(side);

  if (!state["lock_id"])
    return 0;

  if (state["lock_id"] != key_id)
    return 0;

  if (state["locked"])
    return 0;

  state["locked"] = 1;

  return 1;
}

int unlock(int side, object actor, mixed key_id) {
  mapping state = side_state(side);

  if (!state["locked"])
    return 0;

  if (state["lock_id"] && state["lock_id"] != key_id)
    return 0;

  state["locked"] = 0;

  return 1;
}

/* ------------------------------------------------------------ */
/* Configuration helpers
 * ------------------------------------------------------------ */

void set_lock_id(int side, mixed key_id) {
  side_state(side)["lock_id"] = key_id;
}

void set_open_state(int side, int open) {
  side_state(side)["open"] = open;
}

void set_locked_state(int side, int locked) {
  side_state(side)["locked"] = locked;
}

void set_block_message(int side, string msg) {
  side_state(side)["block_msg"] = msg;
}

/* ------------------------------------------------------------ */
/* Examination
 * ------------------------------------------------------------ */

string examine(int side) {
  mapping state = side_state(side);

  if (!state["open"]) {
    if (state["locked"])
      return "A closed, locked door.";
    return "A closed door.";
  }

  return "An open doorway.";
}

