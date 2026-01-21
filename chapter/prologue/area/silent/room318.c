inherit "room/room";

void create() {
  ::create();

  short_desc = "Dark Pit";
  long_desc = "A round shaft drops into darkness, its rim lined with broken stone. Cold air\npools at the mouth and carries the scent of damp earth.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room316",
  ]);

  set_light(1);
}
