#include <globals.h>

/*
 * LINK_D
 *
 * Central Link registrar and authority.
 *
 * - Owns all Link instances
 * - Ensures exactly one Link per endpoint pair
 * - Never loads environments
 * - Never allows Links to be redefined once registered
 *
 * Rooms may DISCOVER Links.
 * World/area code may DEFINE Links.
 */

mapping _links;        /* pair_key -> Link object */
mapping _definitions;  /* pair_key -> definition mapping */

/* ------------------------------------------------------------ */

void create() {
  _links = ([]);
  _definitions = ([]);
}

/* ------------------------------------------------------------ */
/* Utilities
 * ------------------------------------------------------------ */

string normalize_endpoint(string value) {
  if (!stringp(value))
    return "";

  value = trim(value);

  if (value == "")
    return "";

  if (value[0] != '/')
    value = "/" + value;

  return value;
}

/*
 * Order-independent key.
 * Link(A,B) == Link(B,A)
 */
string pair_key(string a, string b) {
  return (a <= b) ? (a + "|" + b) : (b + "|" + a);
}

/* ------------------------------------------------------------ */
/* Definition API (authoritative)
 * ------------------------------------------------------------ */

/*
 * Register a Link definition.
 *
 * definition mapping may contain:
 *   "type"  : string (path to Link prefab/class)
 *   "gates" : array of gate objects or gate definitions
 *   "one_way" : optional mapping ([ from : to ])
 *   other Link-specific config
 *
 * This does NOT instantiate the Link immediately.
 */
int define_link(string env_a, string env_b, mapping definition) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "")
    return 0;

  key = pair_key(a, b);

  if (_definitions[key]) {
    /* Do not silently redefine topology */
    write("Attempt to redefine link.");

    return 0;
  }

  _definitions[key] = definition || ([]);

  return 1;
}

/* ------------------------------------------------------------ */
/* Link instantiation (lazy)
 * ------------------------------------------------------------ */

/*
 * Internal: build a Link from its definition.
 * Called exactly once per endpoint pair.
 */
object _instantiate_link(string a, string b, mapping def) {
  object link;
  object gate;
  int i;

  if (stringp(def["type"]))
    link = new(def["type"]);
  else
    link = new("/core/link");

  link->set_endpoints(a, b);

  /* Optional explicit directionality */
  if (mapp(def["one_way"])) {
    string from = normalize_endpoint(def["one_way"]["from"]);
    string to   = normalize_endpoint(def["one_way"]["to"]);
    if (from && to)
      link->set_one_way(from, to);
  }

  /* Gate stack (ordered A -> B) */
  if (pointerp(def["gates"])) {
    for (i = 0; i < sizeof(def["gates"]); i++) {
      gate = def["gates"][i];
      if (objectp(gate))
        link->add_gate(gate);
    }
  }

  return link;
}

/* ------------------------------------------------------------ */
/* Discovery API (rooms call this)
 * ------------------------------------------------------------ */

/*
 * Get (or lazily create) the Link connecting two endpoints.
 *
 * This NEVER loads environments.
 */
object get_link(string env_a, string env_b) {
  string a, b, key;
  object link;
  mapping def;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "")
    return 0;

  key = pair_key(a, b);

  /* Already instantiated */
  link = _links[key];
  if (objectp(link))
    return link;

  /* Definition required */
  def = _definitions[key];
  if (!mapp(def)) {
    /* Undefined topology is a hard error */
    write("Undefined link requested.");
    return 0;
  }

  link = _instantiate_link(a, b, def);
  _links[key] = link;

  return link;
}

/*
 * Query without instantiating.
 */
object query_link(string env_a, string env_b) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "")
    return 0;

  key = pair_key(a, b);
  return _links[key];
}

/* ------------------------------------------------------------ */
/* Introspection / debugging
 * ------------------------------------------------------------ */

string *defined_links() {
  return keys(_definitions);
}

string *instantiated_links() {
  return keys(_links);
}

