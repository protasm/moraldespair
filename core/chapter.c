inherit "/core/object";

string chapter_title;
string chapter_description;
string chapter_root;
string chapter_start_room;

void set_title(string title) {
  if (!stringp(title))
    return;

  chapter_title = title;

  return;
}

string query_title() {
  return chapter_title;
}

void set_description(string description) {
  if (!stringp(description))
    return;

  chapter_description = description;

  return;
}

string query_description() {
  return chapter_description;
}

void set_root(string root) {
  if (!stringp(root))
    return;

  chapter_root = root;

  return;
}

string query_root() {
  return chapter_root;
}

void set_start_room(string room) {
  if (!stringp(room))
    return;

  chapter_start_room = room;

  return;
}

string query_start_room() {
  return chapter_start_room;
}
