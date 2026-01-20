inherit "room/room";

void create() {
  ::create();

  short_desc = "Open Gate";
  long_desc = "A broken gate stands ajar in a high wall, its hinges rusted solid. The\ncourtyard beyond lies empty and windblown.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room342", "south",
    "chapter/prologue/area/silent/room351", "north",
  });

  set_light(1);
}
