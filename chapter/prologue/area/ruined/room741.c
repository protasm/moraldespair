inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Bunks";
    long_desc = "Rows of low frames line the walls, their slats warped and gray with dust. Mildew softens the plaster, and the floor is worn smooth by vanished footsteps.";
    dest_dir = ([
      "up":"/chapter/prologue/area/ruined/room748",
      "south":"/chapter/prologue/area/ruined/room190",
      "east":"/chapter/prologue/area/ruined/room747",
      "north":"/chapter/prologue/area/ruined/room745",
    ]);

  set_light(1);
}

