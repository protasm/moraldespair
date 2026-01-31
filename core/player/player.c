inherit "/core/object";

#include "player-data.c"

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
  object env = environment(this_object());

  if (env)
    write(env->long() + "\n");
}

/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  object command, location;
  string input, verb, arg, command_path, destination;
  mapping exits;

  if (!stringp(raw))
    return "";

  input = trim(raw);

  if (input == "")
    return "";

  if (sscanf(input, "%s %s", verb, arg) != 2) {
    verb = input;
    arg = "";
  }

  verb = lower_case(verb);

  command_path = "/command/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    command->main(arg);

    return "";
  }

  command_path = "/chapter/prologue/action/" + verb;

  if (file_size(command_path + ".c") >= 0) {
    command = load_object(command_path);

    command->main(arg);

    return "";
  }

  if (!is_direction(verb))
    return raw;

  location = environment(this_object());

  exits = location->exits();
  destination = exits[verb];

  if (!stringp(destination)) {
    write("You can't go that way.\n");

    return "";
  }

  if (destination[0] != '/')
    destination = "/" + destination;

  write("attempting move to " + destination + "\n");
  move_object(destination);

  return "";
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
