inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Steward Office";
  long_desc = "A narrow office holds a broken chair and a faded ledger. The walls are stained\nwhere lamps once burned.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room894",
  ]);

  set_light(1);
}
