inherit "room/room";

void create() {
  ::create();

  short_desc = "Round Door";
  long_desc = "A heavy round door stands in a curved wall, swollen and cracked by time. Moss\ngathers in the seams where the frame once fit tight.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room315", "north",
  });

  set_light(1);
}
