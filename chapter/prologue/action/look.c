inherit "//core/command";

string format_brief_exits(mapping exits) {
  mapping abbreviations;
  string *labels, *keys;
  int i;

  if (!mapp(exits))
    return "(Exits: none)";

  keys = keys(exits);

  if (!sizeof(keys))
    return "(Exits: none)";

  abbreviations = ([
    "north" : "n",
    "south" : "s",
    "east" : "e",
    "west" : "w",
    "northeast" : "ne",
    "northwest" : "nw",
    "southeast" : "se",
    "southwest" : "sw",
    "up" : "u",
    "down" : "d"
  ]);

  labels = allocate(sizeof(keys));
  i = 0;

  while (i < sizeof(keys)) {
    if (stringp(abbreviations[keys[i]]))
      labels[i] = abbreviations[keys[i]];
    else
      labels[i] = keys[i];

    i += 1;
  }

  return "(Exits: " + implode(labels, " ") + ")";
}

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: look or look <target>\n"
    "Show the description of your current location.\n"
    "You can also look at a specific target to inspect it.\n"
  );
}

int main(string arg) {
  object player, location;
  string description, short_desc, divider, exit_line;
  int brief;

  player = this_player();

  if (!objectp(player))
    return 0;

  location = environment(player);

  if (!objectp(location)) {
    write("There is nothing here.\n");

    return 1;
  }

  if (!stringp(arg))
    arg = "";

  arg = trim(arg);

  short_desc = location->short();

  if (arg == "") {
    brief = player->query_brief();

    if (brief) {
      mapping exits;

      if (!stringp(short_desc))
        short_desc = "";

      if (short_desc == "" || short_desc[<1] != '\n')
        short_desc += "\n";

      if (function_exists("dest_dir", location))
        exits = location->dest_dir();
      else
        exits = ([]);

      exit_line = format_brief_exits(exits) + "\n";

      write(short_desc + exit_line);

      return 1;
    }
  }

  description = location->long(arg);

  if (!stringp(description))
    return 0;

  if (!stringp(short_desc))
    short_desc = "";

  divider = "---------+---------+---------+---------+---------+---------+---------+---------+";

  if (short_desc == "" || short_desc[<1] != '\n')
    short_desc += "\n";

  if (divider[<1] != '\n')
    divider += "\n";

  if (arg == "") {
    if (stringp(description) && strlen(description) && description[<1] != '\n')
      description += "\n";
  }

  description = short_desc + divider + description;

  if (strlen(description) && description[<1] != '\n')
    description += "\n";

  write(description);

  return 1;
}
