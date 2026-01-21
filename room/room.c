/*
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */

/* A mapping with directions and destinations: "north":"/room/church" */
mapping dest_dir;

/* Exit aliases: "c":"city" */
mapping exit_aliases;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;
string formatted_long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
string *items;

/* Fact about this room. ex: "no_fight", "no_steal" */
mixed property;

/* No castles are allowed to be dropped here */
int no_castle_flag;

string convert_number(int n);
string *query_numbers();

/* --- Lifecycle --- */

void create() {
  // Initialize containers defensively
  dest_dir = ([]);
  exit_aliases = ([ ]);

  // Sensible defaults
  short_desc = "An unremarkable place";
  long_desc  = "There is nothing of note here.";

  set_light(1);
}

/*
 * init() is called when a player enters scope.
 * This is where command bindings belong.
 */
void init() {
  int i;
  string *aliases;
  string *exit_dirs;

  // Register primary exits
  exit_dirs = m_indices(dest_dir);

  for (i = 0; i < sizeof(exit_dirs); i++)
    add_action("move", exit_dirs[i]);

  // Register alias exits
  aliases = m_indices(exit_aliases);

  for (i = 0; i < sizeof(aliases); i++)
    add_action("move_alias", aliases[i]);
}

int id(string str) {
  int i;

  if (!items)
    return 0;

  while (i < sizeof(items)) {
    if (items[i] == str)
      return 1;

    i += 2;
  }

  return 0;
}

string exitsDescription(int brief) {
  int i;
  int exit_count;
  string desc;
  string *exit_dirs;
  string short_dir;
  string direction;

  if (brief) {
    if (!dest_dir)
      return "(Exits: none)";

    exit_dirs = m_indices(dest_dir);
    exit_count = sizeof(exit_dirs);

    if (exit_count == 0)
      return "(Exits: none)";

    i = 0;
    desc = "(Exits:";

    while (i < exit_count) {
      direction = exit_dirs[i];
      short_dir = (["north":"n",
                    "south":"s", "east":"e", "west":"w", "up":"u", "down":"d",
                    "northeast":"ne", "northwest":"nw", "southeast":"se",
                    "southwest":"sw", ])[direction];

      if (!short_dir)
        short_dir = direction;

      desc += " " + short_dir;
      i += 1;
    }

    return desc + ")";
  }

  if (!dest_dir)
    return "No obvious exits.\n";

  exit_dirs = m_indices(dest_dir);
  exit_count = sizeof(exit_dirs);

  if (exit_count == 0)
    return "No obvious exits.\n";

  i = 0;

  if (exit_count == 1)
    desc = "There is one obvious exit:";
  else
    desc =
        "There are " + convert_number(exit_count) + " obvious exits:";

  while (i < exit_count) {
    desc += " " + exit_dirs[i];
    i += 1;

    if (i == exit_count - 1)
      desc += " and";
    else if (i < exit_count)
      desc += ",";
  }

  return desc + "\n";
}

void long(string str) {
  string ruler, formatted;
  int i;

  if (set_light(0) == 0) {
    write("It is dark.\n");

    return;
  }

  ruler = "---------+---------+---------+---------+---------+---------+---------+---------+";

  if (!str) {
    formatted = formatted_long_desc;

    if (!formatted && long_desc) {
      formatted = "/daemon/text_d"->format_text(long_desc, 80);
      formatted_long_desc = formatted;
    }

    if (!formatted)
      formatted = "";

    write(ruler);
    write("\n" + formatted);
    write("\n\n" + exitsDescription(0));

    return;
  }

  if (!items)
    return;

  i = 0;

  while (i < sizeof(items)) {
    if (items[i] == str) {
      write(items[i + 1] + ".\n");

      return;
    }

    i += 2;
  }
}

/*
 * Does this room have a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
mixed query_property(string str) {
  int i;

  if (str == 0)
    return property;

  if (!property)
    return 0;

  if (stringp(property))
    return str == property;

  while (i < sizeof(property)) {
    if (property[i] == str)
      return 1;

    i += 1;
  }

  return 0;
}

int move(string str) {
  string destination;
  string direction;

  direction = query_verb();
  destination = dest_dir[direction];

  if (!destination)
    return 0;

  this_player()->move_player(direction + "#" + destination);

  return 1;
}

int move_alias(string str) {
  string canonical;
  string destination;

  if (!exit_aliases)
    return 0;

  canonical = exit_aliases[query_verb()];

  if (!canonical)
    return 0;

  destination = dest_dir[canonical];

  if (!destination)
    return 0;

  this_player()->move_player(canonical + "#" + destination);

  return 1;
}

string short() {
  if (set_light(0))
    return short_desc + "\n" + exitsDescription(1);

  return "Dark room";
}

void set_short(string str) {
  short_desc = str;

  return;
}

void set_long(string str) {
  if (!stringp(str)) {
    long_desc = 0;
    formatted_long_desc = 0;

    return;
  }

  long_desc = str + "\n";
  formatted_long_desc = "/daemon/text_d"->format_text(str, 80);

  return;
}

void add_exit_alias(string alias, string canonical) {
  if (!exit_aliases)
    exit_aliases = ([]);

  exit_aliases[alias] = canonical;

  return;
}

mapping query_dest_dir() { return dest_dir; }

string query_long() { return long_desc; }

/*
 * Convert a number to a word. The array is created by the
 * standard room/room, and shared by all rooms.
 */
string *numbers;

string convert_number(int n) {
  if (!pointerp(numbers))
    numbers = query_numbers();

  if (n > 9)
    return "lot of";

  return numbers[n];
}

string *query_numbers() {
  if (!numbers) {
    if (object_name(this_object()) == "room/room")
      numbers = ({"no", "one", "two", "three", "four", "five", "six", "seven",
                  "eight", "nine"});
    else
      numbers = "room/room"->query_numbers();
  }

  return numbers;
}

int query_drop_castle() { return no_castle_flag; }
