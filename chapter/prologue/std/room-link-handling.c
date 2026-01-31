/* Link affordances: label -> Link object */
mapping _links;

/*
 * Register a Link affordance for this room.
 * This does NOT define topology.
 */
void add_link(string label, object link) {
  if (!stringp(label) || !objectp(link))
    return;

  if (!mapp(_links))
    _links = ([]);

  _links[label] = link;
}

/*
 * Resolve a Link by label (used by movement commands).
 */
object query_link(string label) {
  if (!mapp(_links))
    return 0;

  return _links[label];
}

/*
 * Optional: expose available directions for display/debugging.
 */
string *query_link_labels() {
  if (!mapp(_links))
    return ({ });

  return keys(_links);
}

