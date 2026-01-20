inherit "room/room";

void create() {
  ::create();

  short_desc = "North Spur";
  long_desc =
    "The road narrows as the surrounding walls thin. A fragment of mosaic tile\n"
    "glints among the dust.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room267", "south",
    "chapter/prologue/area/anshelm/room1202", "northwest",
    "chapter/prologue/area/anshelm/room274", "north",
  });

  set_light(1);
}
