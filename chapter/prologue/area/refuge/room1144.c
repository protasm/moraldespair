inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent Hall";
  long_desc =
    "Long tables are gone, but their scars remain in the floor. A hearth stands\n"
    "cold beneath a chipped mantle.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1145",
    "west" : "/chapter/prologue/area/refuge/room1138",
  ]);

  set_light(1);
}
