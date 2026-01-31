/*
 * /core/gate.c
 *
 * Abstract base class for all Gates.
 *
 * A Gate is a structural barrier that lives on a Link and mediates
 * traversal between two endpoints. Gates are ordered and directional.
 *
 * Gates:
 *  - are NOT rooms
 *  - are NOT exits
 *  - do NOT move players
 *  - do NOT know about rooms directly
 *
 * Subclasses implement specific mechanics (doors, portals, forcefields).
 */

inherit "/core/object";

/* Internal endpoint identities (never exposed semantically) */
#define SIDE_A 0
#define SIDE_B 1

/* ------------------------------------------------------------ */
/* Internal state */
/* ------------------------------------------------------------ */

/*
 * Each side stores arbitrary state relevant to the subclass.
 * Base class only enforces traversal contract.
 */
mapping _side_a;
mapping _side_b;

/* Base traversal cost (applies regardless of direction) */
int _base_cost;

/* Optional name for narration / inspection */
string _name;

/* ------------------------------------------------------------ */

void create() {
  ::create();

  _side_a = ([]);
  _side_b = ([]);

  _base_cost = 0;
  _name = "gate";
}

/* ------------------------------------------------------------ */
/* Identity & metadata */
/* ------------------------------------------------------------ */

void set_name(string name) {
  _name = name;
}

string query_name() {
  return _name;
}

void set_base_cost(int cost) {
  _base_cost = cost;
}

int query_base_cost() {
  return _base_cost;
}

/* ------------------------------------------------------------ */
/* Side utilities */
/* ------------------------------------------------------------ */

mapping side_state(int side) {
  return side == SIDE_A ? _side_a : _side_b;
}

int opposite_side(int side) {
  return side == SIDE_A ? SIDE_B : SIDE_A;
}

/*
 * Called by Link to translate traversal perspective into a side.
 * endpoint_index is Link-internal (0 or 1).
 */
int side_facing_endpoint(int endpoint_index) {
  return endpoint_index == 0 ? SIDE_A : SIDE_B;
}

/* ------------------------------------------------------------ */
/* Traversal contract (CORE API)
 *
 * Subclasses MUST honor this contract.
 * ------------------------------------------------------------ */

/*
 * Attempt to traverse this gate from the given side.
 *
 * Must return a mapping with:
 *   allow   : int (1 = pass, 0 = block)
 * Optional:
 *   cost    : int (>= 0, added to traversal cost)
 *   effects : array of effect mappings
 *   message : string (actor-facing narration)
 *
 * Base class provides a permissive default.
 */
mapping attempt_pass(object actor, int side) {
  return ([
    "allow"   : 1,
    "cost"    : _base_cost,
    "effects" : ({ }),
  ]);
}

/* ------------------------------------------------------------ */
/* Optional interaction hooks
 * (Subclasses may override)
 * ------------------------------------------------------------ */

/*
 * Examine the gate from a given side.
 */
string examine(int side) {
  return "It appears to be " + _name + ".";
}

/*
 * Whether this gate supports being opened.
 */
int supports_opening() {
  return 0;
}

/*
 * Whether this gate supports locking.
 */
int supports_locking() {
  return 0;
}

/*
 * Default verb handlers (fail closed)
 * Subclasses override as needed.
 */

int open(int side, object actor) {
  return 0;
}

int close(int side, object actor) {
  return 0;
}

int lock(int side, object actor, mixed key) {
  return 0;
}

int unlock(int side, object actor, mixed key) {
  return 0;
}

/* ------------------------------------------------------------ */
/* Debug / introspection (optional but helpful)
 * ------------------------------------------------------------ */

mapping debug_state() {
  return ([
    "name"      : _name,
    "base_cost" : _base_cost,
    "side_a"    : copy(_side_a),
    "side_b"    : copy(_side_b),
  ]);
}
