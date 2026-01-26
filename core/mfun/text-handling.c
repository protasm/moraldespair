#include "text-handling.h"

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
void write(mixed str) {
  string *lines, *wrapped_lines;
  string line, wrapped_line, current, character;
  int i, length;

  if (!stringp(str))
    return;

  lines = ({});
  current = "";
  length = strlen(str);

  for (i = 0; i < length; i++) {
    character = str[i..i];

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

  efun::write(implode(wrapped_lines, "\n"));
}
