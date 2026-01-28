inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "The avenue narrows here, basalt stones dulled to slate by grit and weather. Rust-stained runoff traces the gutter, and a fallen lintel lies along the wall.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room137",
    "north":"/chapter/prologue/area/ruined/room/room135",
  ]);

}
