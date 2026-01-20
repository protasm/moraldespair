inherit "room/room";

void create() {
  ::create();

    short_desc = "Southern Cracked Way";
    long_desc = "Wide paving slabs lie buckled and parted by grass. A line of soot-streaked stone posts leans in slow collapse.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room213", "south",
        "chapter/prologue/area/ruined/room400", "west",
        "chapter/prologue/area/ruined/room401", "east",
        "chapter/prologue/area/ruined/room215", "north",
    });

  set_light(1);
}
