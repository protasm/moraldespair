inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Corner";
  long_desc = "The road turns beside a wall of dark basalt blocks, their faces chipped and rough. A scatter of broken stone marks where another street has slumped away.";
  dest_dir = ({
    "domain/original/area/vesla/room134", "west",
    "domain/original/area/vesla/room132", "east",
    "domain/original/area/vesla/room135", "south",
  });
}
