inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Loose gravel and dirt bury the street's edge. Low foundations crouch in the\nweeds, their doorways open to the air.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room288",
    "east":"/chapter/prologue/area/silent/room290",
    "south":"/chapter/prologue/area/silent/room366",
  ]);

  set_light(1);
}
