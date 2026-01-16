inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Paved Cross";
  long_desc = "A square of broken paving holds the meeting of several paths. The stones are\nsunken and split by roots.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room388", "east",
    "domain/original/area/exedoria/room386", "northwest",
    "domain/original/area/exedoria/room527", "south",
  });
}
