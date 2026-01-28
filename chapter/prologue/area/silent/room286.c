inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Gate";
  long_desc = "A fractured gatehouse leans over the road, its doors long gone. Wind moves\nthrough the empty arch where iron once hung.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room287",
    "exit":"/chapter/prologue/area/silent/entrance",
  ]);

  add_exit_alias("x", "exit");

  set_light(1);
}
