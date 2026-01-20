inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Desk";
  long_desc = "A line of battered cubbies slumps against the wall, clogged with dust. A collapsed counter and scattered tags hint at messages once sorted here, now lost.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room126",
  ]);

  set_light(1);
}
