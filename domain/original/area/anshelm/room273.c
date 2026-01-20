inherit "room/room";

void create() {
  ::create();

  short_desc = "North Spur";
  long_desc =
    "The road narrows as the surrounding walls thin. A fragment of mosaic tile\n"
    "glints among the dust.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room267", "south",
    "domain/original/area/anshelm/room1202", "northwest",
    "domain/original/area/anshelm/room274", "north",
  });

  set_light(1);
}
