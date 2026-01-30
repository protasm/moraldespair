#include <globals.h>

#include "player-data.c"

void create() {
  write("apply create called in player.c\n");

  //enable_commands();
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
  write("apply process_input called in player.c\n");
  write("raw: " + raw + "\n");

  return raw;
}

void catch_tell(string message) {
  write("apply catch_tell called in player.c\n");
  write("message: " + message + "\n");

  return;
}

void gmcp(string message) {
  write("apply gmcp called in player.c\n");

  return;
}

void gmcp_enable(int enabled) {
  write("apply gmcp_enable called in player.c\n");

  return;
}

void logon() {
  write("apply logon called in player.c\n");

  return;
}

void msdp(string message) {
  write("apply msdp called in player.c\n");

  return;
}

void msdp_enable(int enabled) {
  write("apply msdp_enable called in player.c\n");

  return;
}

void msp_enable(int enabled) {
  write("apply msp_enable called in player.c\n");

  return;
}

void mxp_enable(int enabled) {
  write("apply mxp_enable called in player.c\n");

  return;
}

void mxp_tag(string message) {
  write("apply mxp_tag called in player.c\n");

  return;
}

void net_dead() {
  write("apply net_dead called in player.c\n");

  return;
}

void receive_ed(string message) {
  write("apply receive_ed called in player.c\n");

  return;
}

void receive_environ(string message) {
  write("apply receive_environ called in player.c\n");

  return;
}

void receive_message(string clazz, string message) {
  write("apply receive_message called in player.c\n");
  write("class: " + clazz + "\n");
  write("message: " + message + "\n");

  return;
}

void receive_snoop(string message) {
  write("apply receive_snoop called in player.c\n");
  write("message: " + message + "\n");

  return;
}

void telnet_suboption(int option, string message) {
  write("apply telnet_suboption called in player.c\n");
  write("option: " + option + "\n");
  write("message: " + message + "\n");

  return;
}

void terminal_colour_replace(string message) {
  write("apply terminal_colour_replace called in player.c\n");

  return;
}

void terminal_type(string message) {
  write("apply terminal_type called in player.c\n");

  return;
}

void window_size(int width, int height) {
  write("apply window_size called in player.c\n");

  return;
}

void write_prompt() {
  write("apply write_prompt called in player.c\n");
  write(PLAYER_PROMPT);

  return;
}

void zmp(string message) {
  write("apply zmp called in player.c\n");

  return;
}
