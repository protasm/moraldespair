inherit "room/room";

void create() {
  ::create();

  short_desc = "Small Lab";
  long_desc = "A cramped workroom holds tiny benches and cracked tools. The walls are\nblackened by old smoke.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room926", "down",
    "chapter/prologue/area/silent/room930", "up",
  });

  set_light(1);
}
