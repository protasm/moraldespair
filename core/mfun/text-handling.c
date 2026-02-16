/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/mfun/text-handling.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "text-handling.h"
 */

#include "text-handling.h"

/* Method Summary:
 * Purpose:
 *   Handles string wrap_line for this object.
 * Parameters:
 *   - string line
 * Approach:
 *   Validates inputs and executes explicit local logic for string wrap_line.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   private result from string wrap_line.
 */
private string wrap_line(string line) {
  string *tokens, *chunks;
  string current, token, character;
  int i, token_length, length;

  if (!stringp(line) || line == "")
    return "";

  tokens = ({});
  current = "";
  length = strlen(line);

  for (i = 0; i < length; i++) {
    character = line[i..i];

    if (!sizeof(tokens)) {
      tokens += ({ character });

      continue;
    }

    token = tokens[sizeof(tokens) - 1];

    if (character == " ") {
      if (token[0..0] == " ")
        tokens[sizeof(tokens) - 1] += character;
      else
        tokens += ({ character });
    } else {
      if (token[0..0] != " ")
        tokens[sizeof(tokens) - 1] += character;
      else
        tokens += ({ character });
    }
  }

  chunks = ({});

  for (i = 0; i < sizeof(tokens); i++) {
    token = tokens[i];
    token_length = strlen(token);

    if (token_length > 80) {
      if (strlen(current)) {
        chunks += ({ current });
        current = "";
      }

      while (token_length > 80) {
        chunks += ({ token[0..79] });
        token = token[80..];
        token_length = strlen(token);
      }

      if (strlen(token))
        current = token;

      continue;
    }

    if (!strlen(current)) {
      current = token;

      continue;
    }

    if (strlen(current) + token_length <= 80)
      current += token;
    else {
      chunks += ({ current });
      current = token;
    }
  }

  if (strlen(current))
    chunks += ({ current });

  return implode(chunks, "\n");
}

//override
/* Method Summary:
 * Purpose:
 *   Handles wrap_text for this object.
 * Parameters:
 *   - string text
 * Approach:
 *   Wraps text to 80 columns while preserving existing line boundaries.
 * Side effects:
 *   None.
 * Returns:
 *   string result from wrap_text.
 */
string wrap_text(string text) {
  string *lines, *wrapped_lines;
  string line, wrapped_line, current, character;
  int i, length;

  if (!stringp(text))
    return "";

  lines = ({});
  current = "";
  length = strlen(text);

  for (i = 0; i < length; i++) {
    character = text[i..i];

    if (character == "\n") {
      lines += ({ current });
      current = "";

      continue;
    }

    current += character;
  }

  lines += ({ current });
  wrapped_lines = ({});

  for (i = 0; i < sizeof(lines); i++) {
    line = lines[i];
    wrapped_line = wrap_line(line);
    wrapped_lines += ({ wrapped_line });
  }

  return implode(wrapped_lines, "\n");
}

//override
/* Method Summary:
 * Purpose:
 *   Handles write for this object.
 * Parameters:
 *   - mixed str
 * Approach:
 *   Validates inputs and executes explicit local logic for write.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from write.
 */
void write(mixed str) {
  if (!stringp(str))
    return;

  efun::write(wrap_text(str));
}
