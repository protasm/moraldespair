inherit "room/room";

void create() {
  ::create();

    short_desc = "Darkened Crossing";
    long_desc = "Two streets cross in a square of uneven stone. The corners are piled with broken masonry and grit.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room165", "south",
        "chapter/prologue/area/ruined/room192", "east",
        "chapter/prologue/area/ruined/room167", "north",
    });

  set_light(1);
}

