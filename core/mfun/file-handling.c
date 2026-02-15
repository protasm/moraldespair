/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/mfun/file-handling.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/* Method Summary:
 * Purpose:
 *   Handles cat for this object.
 * Parameters:
 *   - string path, int pad_top, int pod_bottom
 * Approach:
 *   Validates inputs and executes explicit local logic for cat.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from cat.
 */
void cat(string path, int pad_top, int pod_bottom) {
  string text;

  if (!stringp(path))
    return;

  text = read_file(path);

  if (!text) {
    write("Unable to read file: " + path + "\n");

    return;
  }

  if (pad_top)
    write("\n");

  write(text);

  if (pad_bottom)
    write("\n");
}

