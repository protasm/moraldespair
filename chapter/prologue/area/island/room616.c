inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = 
    "The street stretches north and south, caught in a cold, unwavering light.\n" +
    "To the east, the muffled roar of the hidden canal vibrates through the\n" +
    "walls of a derelict shop. A massive, ornate structure dominates the\n" +
    "western view, its smooth facade offering no entry. To the south, the\n" +
    "distant glow of the plaza is a dim, dying amber against the gray horizon.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room615",
    "east" : "/chapter/prologue/area/island/room689",
    "north" : "/chapter/prologue/area/island/room617",
  ]);

  set_light(1);
}
