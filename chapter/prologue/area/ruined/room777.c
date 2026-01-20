inherit "room/room";

void create() {
  ::create();

    short_desc = "Low Pens";
    long_desc = "Low pen walls barely stand, their joints loose and sagging. Mildew freckles the timbers, and a damp chill clings to the floor.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room779", "southeast",
        "chapter/prologue/area/ruined/room783", "south",
        "chapter/prologue/area/ruined/room776", "west",
        "chapter/prologue/area/ruined/room778", "east",
        "chapter/prologue/area/ruined/room780", "north",
    });

  set_light(1);
}

