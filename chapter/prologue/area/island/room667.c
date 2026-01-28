inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Guild/Shop Space for rent";
  long_desc = "Guild/Shop Space for rent.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room664",
  ]);

  set_light(1);
}
