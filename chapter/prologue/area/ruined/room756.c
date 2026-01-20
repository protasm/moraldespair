inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Court";
  long_desc = "A wide paved court lies quiet, its cobbles sunken and furred with mildew. Old drain lines and a broken curb hint at orderly traffic long gone.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room755",
    "north":"/chapter/prologue/area/ruined/room757",
  ]);

  set_light(1);
}
