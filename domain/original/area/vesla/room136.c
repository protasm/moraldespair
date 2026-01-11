inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "The avenue narrows here, basalt stones dulled to slate by grit and weather.\n"
              + "Rust-stained runoff traces the gutter, and a fallen lintel lies along the wall.\n";
  dest_dir = ({
    "domain/original/area/vesla/room137", "south",
    "domain/original/area/vesla/room135", "north",
  });
}
