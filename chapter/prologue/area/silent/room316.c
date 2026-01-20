inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Row";
  long_desc = "Wide steps front each entrance, all worn to hollows. Rain has streaked the\ncarved lintels.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room318", "south",
    "chapter/prologue/area/silent/room315", "west",
    "chapter/prologue/area/silent/room317", "east",
    "chapter/prologue/area/silent/room319", "north",
  });

  set_light(1);
}
