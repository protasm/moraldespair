inherit "room/room";

void create() {
  ::create();


  short_desc = "Keep Of Alcibiades";
  long_desc = "Keep Of Alcibiades.\n";
  dest_dir = ({
    "domain/original/area/island/room659", "west",
    "domain/original/area/island/room658", "east",
    "domain/original/area/island/room640", "north",
  });

  set_light(1);
}
