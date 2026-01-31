/*
 * /core/gate_portal.c
 *
 * Concrete Gate subclass implementing portal semantics.
 *
 * A portal:
 *  - is always present
 *  - cannot be opened or closed
 *  - cannot be locked or unlocked
 *  - may allow traversal in one or both directions
 *  - may apply cost or mutations during traversal
 *
 * Examples:
 *  - magical portals
 *  - teleport thresholds
 *  - dream gates
 *  - one-way rifts
 */

inherit "/core/gate";

#define SIDE_A 0
#define SIDE_B 1

/* ------------------------------------------------------------ */
/* Portal state (per side)
 * ------------------------------------------------------------ */

/*
 * passable:
 *   1 -> traversal allowed from this side
 *   0 -> traversal blocked from this side
 *
 * block_msg:
 *   narration when traversal is denied from this side
 */

void create() {
  ::create();

  set_name("shimmering portal");

  side_state(SIDE_A)["passable"]  = 1;
  side_state(SIDE_A)["block_msg"] =
    "The portal shimmers invitingly before you.";

  side_state(SIDE_B)["passable"]  = 0;
  side_state(SIDE_B)["block_msg"] =
    "The portal has no substance from this side.";
}

/* ------------------------------------------------------------ */
/* Capability declarations
 * ------------------------------------------------------------ */

int supports_opening() {
  return 0;
}

int supports_locking() {
  return 0;
}

/* ------------------------------------------------------------ */
/* Traversal logic
 * ------------------------------------------------------------ */

mapping attempt_pass(object actor, int side) {
  mapping state = side_state(side);

  if (!state["passable"]) {
    return ([
      "allow"   : 0,
      "cost"    : query_base_cost(),
      "effects" : ({ }),
      "message" : state["block_msg"],
    ]);
  }

  return ([
    "allow"   : 1,
    "cost"    : query_base_cost(),
    "effects" : ({ }),
  ]);
}

/* ------------------------------------------------------------ */
/* Configuration helpers
 * ------------------------------------------------------------ */

/*
 * Enable or disable traversal from a given side.
 */
void set_passable(int side, int passable) {
  side_state(side)["passable"] = passable;
}

/*
 * Set the denial message for a given side.
 */
void set_block_message(int side, string msg) {
  side_state(side)["block_msg"] = msg;
}

/* ------------------------------------------------------------ */
/* Examination
 * ------------------------------------------------------------ */

string examine(int side) {
  if (side_state(side)["passable"]) {
    return "A rippling portal of light hums softly in the air.";
  }

  return "A wavering distortion hangs here, insubstantial and unreachable.";
}

