inherit "room/room";

void create() {
  ::create();

  short_desc = "Road Start";
  long_desc = "A broader road begins near a low wall of fallen stone. The surface is cracked\nbut still passable.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room385", "west",
    "chapter/prologue/area/silent/room386", "southeast",
    "chapter/prologue/area/silent/room383", "north",
  });

  set_light(1);
}
