inherit "/core/object";

string gate_name;
string closed_message;
int is_open;
object link;
string endpoint;

void create() {
  ::create();

  gate_name = "";
  closed_message = "";
  is_open = 1;
  link = 0;
  endpoint = "";

  return;
}

void set_name(string value) {
  if (!stringp(value))
    return;

  gate_name = value;
}

string query_name() {
  return gate_name;
}

void set_closed_message(string value) {
  if (!stringp(value))
    return;

  closed_message = value;
}

string query_closed_message() {
  return closed_message;
}

void set_open(int value) {
  is_open = value;
}

int query_open() {
  return is_open;
}

void set_link(object value) {
  if (!objectp(value))
    return;

  link = value;
}

object query_link() {
  return link;
}

void set_endpoint(string value) {
  if (!stringp(value))
    return;

  endpoint = value;
}

string query_endpoint() {
  return endpoint;
}

int blocks_traversal(object actor, string origin, string destination) {
  if (is_open)
    return 0;

  return 1;
}

string blocked_message(object actor, string origin, string destination) {
  if (closed_message != "")
    return closed_message;

  if (gate_name != "")
    return "The " + gate_name + " blocks the way.";

  return "Something blocks the way.";
}
