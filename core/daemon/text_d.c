/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/text_d.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "/core/daemon/text_d.h"
 */

/*
 * text_d.c
 *
 * Utility daemon for formatting arbitrary text into wrapped paragraphs.
 * The daemon stores no state and can be called safely from anywhere.
 */

#include "/core/daemon/text_d.h"

/* Method Summary:
 * Purpose:
 *   Handles is_space for this object.
 * Parameters:
 *   - int c
 * Approach:
 *   Validates inputs and executes explicit local logic for is_space.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_space.
 */
int is_space(int c) {
  if (c <= 32) return 1;

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles replace_string for this object.
 * Parameters:
 *   - string input, string search, string replacement
 * Approach:
 *   Validates inputs and executes explicit local logic for replace_string.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from replace_string.
 */
string replace_string(string input, string search, string replacement) {
  string *parts;

  if (!stringp(input)) {
    return "";
  }

  if (!stringp(search) || search == "") {
    return input;
  }

  if (!stringp(replacement)) {
    replacement = "";
  }

  parts = explode(input, search);

  return implode(parts, replacement);
}

/* Method Summary:
 * Purpose:
 *   Handles trim_whitespace for this object.
 * Parameters:
 *   - string text
 * Approach:
 *   Validates inputs and executes explicit local logic for trim_whitespace.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from trim_whitespace.
 */
string trim_whitespace(string text) {
  int start, end, length;

  if (!stringp(text)) {
    return "";
  }

  length = sizeof(text);
  start = 0;
  end = length - 1;

  while (start <= end && is_space(text[start])) {
    start += 1;
  }

  while (end >= start && is_space(text[end])) {
    end -= 1;
  }

  if (start > end) {
    return "";
  }

  return text[start..end];
}

/* Method Summary:
 * Purpose:
 *   Handles split_words for this object.
 * Parameters:
 *   - string text
 * Approach:
 *   Validates inputs and executes explicit local logic for split_words.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from split_words.
 */
string *split_words(string text) {
  string *words;
  string trimmed, current;
  int i, length;

  trimmed = trim_whitespace(text);
  words = ({});
  current = "";
  length = sizeof(trimmed);
  i = 0;

  while (i < length) {
    if (is_space(trimmed[i])) {
      if (current != "") {
        words += ({ current });
        current = "";
      }
    } else {
      current += trimmed[i..i];
    }

    i += 1;
  }

  if (current != "") {
    words += ({ current });
  }

  return words;
}

/* Method Summary:
 * Purpose:
 *   Handles format_paragraph for this object.
 * Parameters:
 *   - string text, int max_width
 * Approach:
 *   Validates inputs and executes explicit local logic for format_paragraph.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from format_paragraph.
 */
string format_paragraph(string text, int max_width) {
  string *words;
  string output, line, word;
  int i, line_len, word_len;

  words = split_words(text);
  output = "";
  line = "";
  line_len = 0;
  i = 0;

  while (i < sizeof(words)) {
    word = words[i];
    word_len = sizeof(word);

    if (line == "") {
      line = word;
      line_len = word_len;
    } else if (line_len + 1 + word_len <= max_width) {
      line += " " + word;
      line_len += 1 + word_len;
    } else {
      if (output != "") {
        output += "\n";
      }

      output += line;
      line = word;
      line_len = word_len;
    }

    i += 1;
  }

  if (line != "") {
    if (output != "") {
      output += "\n";
    }

    output += line;
  }

  return output;
}

/*
 * Preserve paragraph breaks while normalizing whitespace into wrapped lines.
 */
/* Method Summary:
 * Purpose:
 *   Handles format_text for this object.
 * Parameters:
 *   - string input, int max_width
 * Approach:
 *   Validates inputs and executes explicit local logic for format_text.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from format_text.
 */
string format_text(string input, int max_width) {
  string normalized, paragraph, output, formatted, line, trimmed;
  string *lines;
  int i;

  if (!stringp(input)) {
    return "";
  }

  if (!max_width) {
    max_width = 80;
  }

  normalized = replace_string(input, "\r\n", "\n");
  normalized = replace_string(normalized, "\r", "\n");

  lines = explode(normalized, "\n");
  paragraph = "";
  output = "";
  i = 0;

  while (i < sizeof(lines)) {
    line = lines[i];
    trimmed = trim_whitespace(line);

    if (trimmed == "") {
      if (paragraph != "") {
        formatted = format_paragraph(paragraph, max_width);

        if (output != "") {
          output += "\n\n";
        }

        output += formatted;
        paragraph = "";
      }
    } else {
      if (paragraph == "") {
        paragraph = trimmed;
      } else {
        paragraph += " " + trimmed;
      }
    }

    i += 1;
  }

  if (paragraph != "") {
    formatted = format_paragraph(paragraph, max_width);

    if (output != "") {
      output += "\n\n";
    }

    output += formatted;
  }

  return output;
}

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
  return;
}
