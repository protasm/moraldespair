#include <globals.h>

mapping links;

void create() {
  links = ([]);

  return;
}

/****************************************************************************
 *
 * Link Registrar
 * --------------
 * Stores endpoint identifiers as strings and never loads environments.
 * Each endpoint pair resolves to a single shared Link instance.
 *
 ****************************************************************************/

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

string pair_key(string first, string second) {
  if (first <= second)
    return first + "|" + second;

  return second + "|" + first;
}

object get_link(string env_a, string env_b) {
  object link;
  string endpoint_a, endpoint_b;
  string key;

  endpoint_a = normalize_endpoint(env_a);
  endpoint_b = normalize_endpoint(env_b);

  if (endpoint_a == "" || endpoint_b == "")
    return 0;

  key = pair_key(endpoint_a, endpoint_b);
  link = links[key];

  if (objectp(link))
    return link;

  link = new("/core/link");
  link->set_endpoints(endpoint_a, endpoint_b);
  links[key] = link;

  return link;
}

object query_link(string env_a, string env_b) {
  string endpoint_a, endpoint_b;
  string key;

  endpoint_a = normalize_endpoint(env_a);
  endpoint_b = normalize_endpoint(env_b);

  if (endpoint_a == "" || endpoint_b == "")
    return 0;

  key = pair_key(endpoint_a, endpoint_b);

  return links[key];
}
