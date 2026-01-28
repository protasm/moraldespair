inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Alley Mouth";
  long_desc = "A narrow opening splits the row of buildings, leading into shadow. The lintel\nabove is cracked and sagging.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room328",
    "north":"/chapter/prologue/area/silent/room303",
  ]);

  set_light(1);
}
