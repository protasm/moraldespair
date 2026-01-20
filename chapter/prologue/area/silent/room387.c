inherit "room/room";

void create() {
  ::create();

  short_desc = "Paved Cross";
  long_desc = "A square of broken paving holds the meeting of several paths. The stones are\nsunken and split by roots.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room388", "east",
    "chapter/prologue/area/silent/room386", "northwest",
    "chapter/prologue/area/silent/room527", "south",
  });

  set_light(1);
}
