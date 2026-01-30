#include <globals.h>

#include "player-data.c"

void create() {
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
write("process_input " + raw + "\n");
  return raw;
}

void write_prompt() {
  write(PLAYER_PROMPT);
}
