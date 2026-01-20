inherit "room/room";

void create() {
  ::create();

    short_desc = "Southern Cracked Way";
    long_desc = "Wide paving slabs lie buckled and parted by grass. A line of soot-streaked stone posts leans in slow collapse.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room213",
      "west":"/chapter/prologue/area/ruined/room400",
      "east":"/chapter/prologue/area/ruined/room401",
      "north":"/chapter/prologue/area/ruined/room215",
    ]);

  set_light(1);
}
