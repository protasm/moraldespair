/*
 * text_d.c
 *
 * Utility daemon for formatting arbitrary text into wrapped paragraphs.
 * The daemon stores no state and can be called safely from anywhere.
 */

int is_space(int c) {
  if (c <= 32) return 1;

  return 0;
}

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

void create() {
  return;
}
