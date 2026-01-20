inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The main road bends toward the gate, its stones worn thin and pale. A line of old posts leans toward the center.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room166", "south",
        "chapter/prologue/area/ruined/room168", "north",
    });

  set_light(1);
}

