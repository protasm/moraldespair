string short_desc;
string long_desc;
mapping dest_dir;
mapping exit_aliases;

void create() {
  dest_dir = ([]);
  exit_aliases = ([]);

  return;
}

void init() {
  string *dirs;
  string *aliases;
  int i;

  if (mappingp(dest_dir))
    dirs = m_indices(dest_dir);
  else
    dirs = ({ });

  if (mappingp(exit_aliases))
    aliases = m_indices(exit_aliases);
  else
    aliases = ({ });
  i = 0;

  while (pointerp(dirs) && i < sizeof(dirs)) {
    add_action("move", dirs[i]);
    i += 1;
  }

  i = 0;

  while (pointerp(aliases) && i < sizeof(aliases)) {
    add_action("move_alias", aliases[i]);
    i += 1;
  }

  return;
}

string short() {
  if (stringp(short_desc))
    return short_desc;

  return "Room";
}

string query_short() {
  return short();
}

void long(string str) {
  string desc;
  int length;

  desc = long_desc;
  if (stringp(desc)) {
    write(desc);

    length = strlen(desc);
    if (length == 0 || desc[length - 1] != '\n')
      write("\n");
  } else {
    write("Nothing stands out here.\n");
  }

  return;
}

string query_long() {
  return long_desc;
}

mapping query_dest_dir() {
  return dest_dir;
}

mapping query_exit_aliases() {
  return exit_aliases;
}

void add_exit_alias(string alias, string direction) {
  if (!exit_aliases)
    exit_aliases = ([]);

  exit_aliases[alias] = direction;

  return;
}

int move(string str) {
  string direction;

  direction = query_verb();

  return move_direction(direction);
}

int move_alias(string str) {
  string alias;
  string canonical;

  alias = query_verb();
  if (!exit_aliases) return 0;

  canonical = exit_aliases[alias];
  if (!canonical) return 0;

  return move_direction(canonical);
}

int move_direction(string direction) {
  string destination;

  if (!mappingp(dest_dir))
    return 0;

  destination = dest_dir[direction];
  if (!stringp(destination))
    return 0;

  if (destination[0] != '/')
    destination = "/" + destination;

  this_player()->move_player(direction + "#" + destination);

  return 1;
}
