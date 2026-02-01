inherit "/core/object";

#include "player-data.c"
#include "player-process-input.c"

void create() {
  ::create();

  enable_commands();
  set_heart_beat(1);
}

void heart_beat() {
  ::heart_beat();
}

int is_living() {
  return 1;
}

void show_location() {
  object env;
  string short_desc, long_desc;
  mapping exits;
  string *dirs;
  string divider;

  env = environment(this_object());

  if (!objectp(env)) {
    write("You are nowhere.\n");

    return;
  }

  divider = "---------+---------+---------+---------+---------+---------+---------+---------+";

  short_desc = env->short();

  if (stringp(short_desc) && short_desc != "")
    write(short_desc + "\n");

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
