inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "The street lies uneven, its stones tilted and split. Vines trail across the\nroad in slow, careless loops.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room294",
    "west":"/chapter/prologue/area/silent/room292",
  ]);

  set_light(1);
}
