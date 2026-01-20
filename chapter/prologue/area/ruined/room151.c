inherit "room/room";

void create() {
  ::create();

    short_desc = "River-Main Junction";
    long_desc = "Two dead roads cross in a scatter of broken cobbles. A fractured drain grate sits at the center, packed with mud and leaves.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room816", "south",
        "chapter/prologue/area/ruined/room150", "west",
        "chapter/prologue/area/ruined/room205", "east",
        "chapter/prologue/area/ruined/room152", "north",
    });

  set_light(1);
}

