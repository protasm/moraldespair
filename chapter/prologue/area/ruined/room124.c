inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Canopy";
  long_desc = "The cover above the walk has failed, opening to a pale strip of sky. Loose stones and splintered wood lie scattered, and the ground shows long years of weathering.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room125", "west",
    "chapter/prologue/area/ruined/room123", "east",
    "chapter/prologue/area/ruined/room412", "north",
  });

  set_light(1);
}
