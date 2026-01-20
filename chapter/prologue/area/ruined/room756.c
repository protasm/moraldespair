inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Court";
  long_desc = "A wide paved court lies quiet, its cobbles sunken and furred with mildew. Old drain lines and a broken curb hint at orderly traffic long gone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room755", "south",
    "chapter/prologue/area/ruined/room757", "north",
  });

  set_light(1);
}
