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

string property(string name) {
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

string category() {
  return property("category");
}

void set_help_text(string value) {
  if (!stringp(value))
    return;

  set_property("help-text", value);
}

string help_text() {
  return property("help-text");
}
