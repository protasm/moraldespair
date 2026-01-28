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

