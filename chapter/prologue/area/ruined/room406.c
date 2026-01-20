inherit "room/room";

void create() {
  ::create();

  short_desc = "Wax Alcove";
  long_desc = "A side chamber is lined with niche shelves, now empty and gray with dust. Wax drips have hardened on the floor, their puddles greened by mildew and tracked with grit from a door that no longer shuts.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room405",
  ]);

  set_light(1);
}
