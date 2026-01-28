inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "House of Balin";
  long_desc = "House of Balin.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room712",
    "south" : "/chapter/prologue/area/island/room654",
  ]);

  set_light(1);
}
