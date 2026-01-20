inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "The street here is broad, its stones worn smooth in places. Small piles of\nrubble mark fallen doorways.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room335", "west",
    "chapter/prologue/area/silent/room337", "east",
    "chapter/prologue/area/silent/room602", "north",
  });

  set_light(1);
}
