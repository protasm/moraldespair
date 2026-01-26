string wrap_line(string line) {
  string *words, *chunks;
  string current, word;
  int i, word_length;

  if (!stringp(line) || line == "")
    return "";

  words = explode(line, " ");
  chunks = ({});
  current = "";

  for (i = 0; i < sizeof(words); i++) {
    word = words[i];

    if (word == "")
      continue;

    word_length = strlen(word);

    if (word_length > 80) {
      if (strlen(current)) {
        chunks += ({ current });
        current = "";
      }

      while (word_length > 80) {
        chunks += ({ word[0..79] });
        word = word[80..];
        word_length = strlen(word);
      }

      if (strlen(word))
        current = word;

      continue;
    }

    if (!strlen(current)) {
      current = word;

      continue;
    }

    if (strlen(current) + 1 + word_length <= 80)
      current += " " + word;
    else {
      chunks += ({ current });
      current = word;
    }
  }

  if (strlen(current))
    chunks += ({ current });

  return implode(chunks, "\n");
}

//override
void write(mixed str) {
  string *lines, *wrapped_lines;
  string line, wrapped_line;
  int i;

  if (!stringp(str))
    return;

  lines = explode(str, "\n");
  wrapped_lines = ({});

  for (i = 0; i < sizeof(lines); i++) {
    line = lines[i];
    wrapped_line = wrap_line(line);
    wrapped_lines += ({ wrapped_line });
  }

  efun::write(implode(wrapped_lines, "\n"));
}
