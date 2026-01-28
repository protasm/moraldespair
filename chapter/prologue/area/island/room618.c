inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = 
    "The pavement here is fractured and charred, leading toward the jagged\n" +
    "base of a mountain to the north. To the east, the walls of a blackened\n" +
    "structure still radiate a dull, rhythmic heat, pulsing like a dying\n" +
    "ember. Opposite this warmth stands a silent arena, its entrance yawning\n" +
    "open beneath a fixed 'Closed' sign. Thick plumes of steam rise from the\n" +
    "northern rocks, veiling the path where the silver road finally dissolves\n" +
    "into stone and dust.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room617",
    "west" : "/chapter/prologue/area/island/room622",
    "east" : "/chapter/prologue/area/island/room691",
    "north" : "/chapter/prologue/area/island/room619",
  ]);

  set_light(1);
}
