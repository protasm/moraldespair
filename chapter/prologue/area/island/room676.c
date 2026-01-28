inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Mariner's Revenge";
  long_desc = "Mariner's Revenge.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room613",
    "north" : "/chapter/prologue/area/island/room677",
  ]);

  set_light(1);
}
