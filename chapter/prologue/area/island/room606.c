inherit "room/room";

void create() {
  ::create();


  short_desc = "A sandy beachhead";
  long_desc = "Shattered timber from a fallen pier litters the shoreline, half-buried in\n" +
    "shifting sands. To the north, the silent spires of a vacant city loom over\n" +
    "the dunes like jagged teeth against a stagnant twilight. The rotted ribs\n" +
    "of a great yacht emerge from the surf to the east, stripped of all glory.\n" +
    "Only the rhythmic thundering of the western falls breaks the heavy silence.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room605",
    "west" : "/chapter/prologue/area/island/room623",
    "east" : "/chapter/prologue/area/island/room626",
    "north" : "/chapter/prologue/area/island/room607",
  ]);

  set_light(1);
}
