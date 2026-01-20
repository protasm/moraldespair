inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Trough";
    long_desc = "A stone trough is split down the middle, its basin crusted with lime. Rot has eaten the surrounding planks, leaving gaps filled with dust and mold.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room782",
      "west":"/chapter/prologue/area/ruined/room775",
      "east":"/chapter/prologue/area/ruined/room777",
      "north":"/chapter/prologue/area/ruined/room781",
    ]);

  set_light(1);
}

