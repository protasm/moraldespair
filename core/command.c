mapping properties;

void create() {
  properties = ([]);

  properties["category"] = "General";
  properties["help-text"] = "No help text is available for this command.";
}

void set_property(string name, string value) {
  if (!stringp(name))
    return;

  if (!mapp(properties))
    properties = ([]);

  properties[name] = value;
}

string query_property(string name) {
  if (!stringp(name))
    return "";

  if (!mapp(properties))
    properties = ([]);

  return properties[name];
}

void set_category(string value) {
  if (!stringp(value))
    return;

  set_property("category", value);
}

string query_category() {
  return query_property("category");
}

void set_help_text(string value) {
  if (!stringp(value))
    return;

  set_property("help-text", value);
}

string query_help_text() {
  return query_property("help-text");
}
