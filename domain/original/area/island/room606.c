inherit "room/room";

void create() {
  ::create();


  short_desc = "A sandy beachhead";
  long_desc = "Shattered timber from a fallen pier litters the shoreline, half-buried in\n" +
    "shifting sands. To the north, the silent spires of a vacant city loom over\n" +
    "the dunes like jagged teeth against a stagnant twilight. The rotted ribs\n" +
    "of a great yacht emerge from the surf to the east, stripped of all glory.\n" +
    "Only the rhythmic thundering of the western falls breaks the heavy silence.\n";
  dest_dir = ({
    "domain/original/area/island/room605", "south",
    "domain/original/area/island/room623", "west",
    "domain/original/area/island/room626", "east",
    "domain/original/area/island/room607", "north",
  });

  set_light(1);
}
