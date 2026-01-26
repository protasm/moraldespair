#include "text-handling.h"

private string wrap_line(string line) {
  string *tokens, *chunks;
  string current, token, character;
  int i, token_length, length;

  if (!efun::stringp(line) || line == "")
    return "";

  tokens = ({});
  current = "";
  length = efun::strlen(line);

  for (i = 0; i < length; i++) {
    character = line[i..i];

    if (!efun::sizeof(tokens)) {
      tokens += ({ character });

      continue;
    }

    token = tokens[efun::sizeof(tokens) - 1];

    if (character == " ") {
      if (token[0..0] == " ")
        tokens[efun::sizeof(tokens) - 1] += character;
      else
        tokens += ({ character });
    } else {
      if (token[0..0] != " ")
        tokens[efun::sizeof(tokens) - 1] += character;
      else
        tokens += ({ character });
    }
  }

  chunks = ({});

  for (i = 0; i < efun::sizeof(tokens); i++) {
    token = tokens[i];
    token_length = efun::strlen(token);

    if (token_length > 80) {
      if (efun::strlen(current)) {
        chunks += ({ current });
        current = "";
      }

      while (token_length > 80) {
        chunks += ({ token[0..79] });
        token = token[80..];
        token_length = efun::strlen(token);
      }

      if (efun::strlen(token))
        current = token;

      continue;
    }

    if (!efun::strlen(current)) {
      current = token;

      continue;
    }

    if (efun::strlen(current) + token_length <= 80)
      current += token;
    else {
      chunks += ({ current });
      current = token;
    }
  }

  if (efun::strlen(current))
    chunks += ({ current });

  return efun::implode(chunks, "\n");
}

//override
void write(mixed str) {
  string *lines, *wrapped_lines;
  string line, wrapped_line, current, character;
  int i, length;

  if (!efun::stringp(str))
    return;

  lines = ({});
  current = "";
  length = efun::strlen(str);

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

  for (i = 0; i < efun::sizeof(lines); i++) {
    line = lines[i];
    wrapped_line = wrap_line(line);
    wrapped_lines += ({ wrapped_line });
  }

  efun::write(efun::implode(wrapped_lines, "\n"));
}
