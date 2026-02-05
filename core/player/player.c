inherit "/core/object";

#include "player-data.c"
#include "player-process-input.c"

void create() {
  ::create();

  enable_commands();
  set_heart_beat(1);

  if (is_wizard()) {
    write("Enabling wizard privileges...");

    enable_wizard();

    write(" done!\n");
  }
}

void heart_beat() {
  ::heart_beat();
}

int is_living() {
  return 1;
}

void check_wizard() {
  int is_wizard;

  is_wizard = is_wizard();

  if (is_wizard) {
    write("Enabling wizard commands...");

    enable_wizard();

    write(" done!\n");
  }
}

string abbreviate_exit(string direction) {
  mapping abbreviations;
  string abbreviated;

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

  abbreviated = abbreviations[direction];

  if (stringp(abbreviated))
    return abbreviated;

  return direction;
}

void show_location(int force_verbose, int show_path) {
  object env;
  string short_desc, long_desc, divider, room_path, header;
  mapping exits;
  string *dirs, *abbr_dirs;
  int brief, i;

  env = environment(this_object());

  if (!objectp(env)) {
    write("You are nowhere.\n");

    return;
  }

  if (!force_verbose)
    brief = query_brief();

  if (brief) {
    short_desc = env->short();

    if (stringp(short_desc) && short_desc != "")
      write(short_desc + "\n");

    exits = LINK_D->links_by_direction_for_room(base_name(env));

    if (mapp(exits) && sizeof(exits)) {
      dirs = sort_array(keys(exits), 1);
      abbr_dirs = ({});

      for (i = 0; i < sizeof(dirs); i++)
        abbr_dirs += ({ abbreviate_exit(dirs[i]) });

      write("[Exits: " + implode(abbr_dirs, " ") + "]\n");
    } else
      write("[Exits: none]\n");

    return;
  }

  divider = "---------+---------+---------+---------+---------+---------+---------+---------+";

  short_desc = env->short();
  room_path = base_name(env);
  header = short_desc;

  if (show_path && stringp(short_desc) && short_desc != "" &&
    stringp(room_path) && room_path != "")
    header = short_desc + " (" + room_path + ")";

  if (stringp(header) && header != "") {
    if (show_path)
      write("\n");

    write(header + "\n");
  }

  write(divider + "\n");

  long_desc = env->long();

  if (stringp(long_desc) && long_desc != "") {
    write(long_desc);

    if (long_desc[<1] != '\n')
      write("\n");
  }

  write("\n");

  exits = LINK_D->links_by_direction_for_room(base_name(env));

  if (mapp(exits) && sizeof(exits)) {
    dirs = sort_array(keys(exits), 1);

    write("Exits: " + implode(dirs, ", ") + "\n");
  } else {
    write("Exits: none\n");
  }
}

void catch_tell(string message) {
  return;
}

void gmcp(string message) {
  return;
}

void gmcp_enable(int enabled) {
  return;
}

void logon() {
  return;
}

void msdp(string message) {
  return;
}

void msdp_enable(int enabled) {
  return;
}

void msp_enable(int enabled) {
  return;
}

void mxp_enable(int enabled) {
  return;
}

void mxp_tag(string message) {
  return;
}

void net_dead() {
  return;
}

void receive_ed(string message) {
  return;
}

void receive_environ(string message) {
  return;
}

void receive_message(string clazz, string message) {
  return;
}

void receive_snoop(string message) {
  return;
}

void telnet_suboption(int option, string message) {
  return;
}

void terminal_colour_replace(string message) {
  return;
}

void terminal_type(string message) {
  return;
}

void window_size(int width, int height) {
  return;
}

void write_prompt() {
  write(PLAYER_PROMPT);

  return;
}

void zmp(string message) {
  return;
}
