inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "Thin weeds stripe the main road here, forcing a crooked path. A low curb has crumbled into the street, leaving a scatter of chips.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room153", "south",
        "chapter/prologue/area/ruined/room821", "east",
        "chapter/prologue/area/ruined/room155", "north",
    });

  set_light(1);
}


