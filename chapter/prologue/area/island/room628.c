inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "A valley between two large dunes";
  long_desc = "A valley between two large dunes.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room629",
    "west" : "/chapter/prologue/area/island/room607",
  ]);

  set_light(1);
}
