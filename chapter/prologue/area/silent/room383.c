inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Post";
  long_desc = "A simple post of stone stands abandoned at the corner. Only a cracked bench\nremains inside.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room384", "south",
    "chapter/prologue/area/silent/room292", "north",
  });

  set_light(1);
}
