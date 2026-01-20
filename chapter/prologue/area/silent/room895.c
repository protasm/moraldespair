inherit "room/room";

void create() {
  ::create();

  short_desc = "Common Hall";
  long_desc = "Long tables stand in a wide hall, their surfaces split and gray. A cold hearth\nsits at the far end.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room894", "north",
  });

  set_light(1);
}
