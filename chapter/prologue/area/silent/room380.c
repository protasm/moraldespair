inherit "room/room";

void create() {
  ::create();

  short_desc = "Gravel Cross";
  long_desc = "Gravel paths meet in a small clearing of trampled stone. One branch is almost\nlost beneath grass.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room379", "west",
    "chapter/prologue/area/silent/room382", "southeast",
    "chapter/prologue/area/silent/room381", "north",
  });

  set_light(1);
}
