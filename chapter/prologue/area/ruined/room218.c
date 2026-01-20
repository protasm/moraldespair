inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "Loose stones crunch under a thin coat of dust. A rusted bracket clings to the wall, its mate long gone.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room217",
      "north":"/chapter/prologue/area/ruined/room219",
    ]);

  set_light(1);
}
