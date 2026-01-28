inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "East Roof";
  long_desc =
    "The roof of the eastern spire is open to the weather, its parapet broken. A\n"
    "lone flagpole lies across the stones.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1151",
  ]);

  set_light(1);
}
