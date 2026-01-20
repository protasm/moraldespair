inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "The avenue narrows here, basalt stones dulled to slate by grit and weather. Rust-stained runoff traces the gutter, and a fallen lintel lies along the wall.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room137", "south",
    "chapter/prologue/area/ruined/room135", "north",
  });
}
