inherit "/core/object";

#include "player-data.c"

void create() {
  ::create();

  write("PLAYER:create()\n");

  enable_commands();
}

void show_location() {
  object env = environment(this_object());

  if (env)
    write(env->long());
  else
    write("Ain't got no env.\n");
}

/****************************************************************************
 * Called automatically by the FluffOS driver for each line of user input.
 ****************************************************************************/
string process_input(string raw) {
  write("PLAYER:process_input()\n");
  write("raw: " + raw + "\n");

  return raw;
}

void catch_tell(string message) {
  write("PLAYER:catch_tell()\n");
  write("message: " + message + "\n");

  return;
}

void gmcp(string message) {
  write("PLAYER:gmcp()\n");

  return;
}

void gmcp_enable(int enabled) {
  write("PLAYER:gmcp_enable()\n");

  return;
}

void logon() {
  write("PLAYER:logon()\n");

  return;
}

void msdp(string message) {
  write("PLAYER:msdp()\n");

  return;
}

void msdp_enable(int enabled) {
  write("PLAYER:msdp_enable()\n");

  return;
}

void msp_enable(int enabled) {
  write("PLAYER:msp_enable()\n");

  return;
}

void mxp_enable(int enabled) {
  write("PLAYER:mxp_enable()\n");

  return;
}

void mxp_tag(string message) {
  write("PLAYER:mxp_tag()\n");

  return;
}

void net_dead() {
  write("PLAYER:net_dead()\n");

  return;
}

void receive_ed(string message) {
  write("PLAYER:receive_ed()\n");

  return;
}

void receive_environ(string message) {
  write("PLAYER:receive_environ()\n");

  return;
}

void receive_message(string clazz, string message) {
  write("PLAYER:receive_message()\n");
  write("class: " + clazz + "\n");
  write("message: " + message + "\n");

  return;
}

void receive_snoop(string message) {
  write("PLAYER:receive_snoop()\n");
  write("message: " + message + "\n");

  return;
}

void telnet_suboption(int option, string message) {
  write("PLAYER:telnet_suboption()\n");
  write("option: " + option + "\n");
  write("message: " + message + "\n");

  return;
}

void terminal_colour_replace(string message) {
  write("PLAYER:terminal_colour_replace()\n");
  write("-- message: " + message + "\n");

  return;
}

void terminal_type(string message) {
  write("PLAYER:terminal_type()\n");

  return;
}

void window_size(int width, int height) {
  write("PLAYER:window_size()\n");
  write("-- width: " + width + "\n");
  write("-- height: " + height + "\n");

  return;
}

void write_prompt() {
  write("PLAYER:write_prompt()\n");
  write(PLAYER_PROMPT);

  return;
}

void zmp(string message) {
  write("PLAYER:zmp()\n");
  write("-- message: " + message + "\n");

  return;
}
