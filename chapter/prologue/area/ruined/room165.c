inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The north road levels out and grows quiet, its surface scabbed with grit. A cracked iron grate lies in the gutter.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room164", "south",
        "chapter/prologue/area/ruined/room166", "north",
    });

  set_light(1);
}

