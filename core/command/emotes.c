/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/emotes.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 */

inherit "/core/command/command";

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: emotes\n"
    "The emotes command provides a sample of emotes.\n"
    "Try one with a target, for example: smile at <target>\n"
  );
}

/* Method Summary:
 * Purpose:
 *   Handles main for this object.
 * Parameters:
 *   - string arg
 * Approach:
 *   Reads the avatar soul-emote catalog, samples five emote names at
 *   random, and prints them directly to the player.
 * Side effects:
 *   Writes command output to the player.
 * Returns:
 *   int result from main.
 */
int main(string arg) {
  object avatar;
  mapping emotes;
  string *catalog;
  string output;
  int i;
  int sample_count;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  emotes = ([]);

  if (function_exists("soul_emotes", avatar))
    emotes = avatar->soul_emotes();

  if (!mapp(emotes) || !sizeof(keys(emotes))) {
    write("No emotes are currently available.\n");

    return 1;
  }

  catalog = keys(emotes);

  if (sizeof(catalog) > 1)
    catalog = shuffle(catalog);

  sample_count = 5;

  if (sizeof(catalog) < sample_count)
    sample_count = sizeof(catalog);

  output = "Available emotes include:\n";

  for (i = 0; i < sample_count; i++) {
    output += catalog[i];

    if (i < sample_count - 1)
      output += ", ";
  }

  output += "\nAnd many more!\n";
  write(output);

  return 1;
}
