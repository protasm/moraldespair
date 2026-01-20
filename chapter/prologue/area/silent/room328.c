inherit "room/room";

void create() {
  ::create();

  short_desc = "Dark Alley";
  long_desc = "The alley lies in permanent shade, its stones damp and uneven. Refuse has long\nsince rotted into the cracks.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room327", "south",
    "chapter/prologue/area/silent/room329", "north",
  });

  set_light(1);
}
