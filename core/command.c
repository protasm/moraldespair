#include <globals.h>

inherit CLEAN_UP;

mapping properties;

void create() {
  properties = ([]);

  properties["category"] = "General";
  properties["help-text"] = "No help text is available for this command.";
}

void set_property(string name, string value) {
  if (!efun::stringp(name))
    return;

  if (!efun::mapp(properties))
    properties = ([]);

  properties[name] = value;
}

string query_property(string name) {
  if (!efun::stringp(name))
    return "";

  if (!efun::mapp(properties))
    properties = ([]);

  return properties[name];
}

void set_category(string value) {
  if (!efun::stringp(value))
    return;

  set_property("category", value);
}

string query_category() {
  return query_property("category");
}

void set_help_text(string value) {
  if (!efun::stringp(value))
    return;

  set_property("help-text", value);
}

string query_help_text() {
  return query_property("help-text");
}
