inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The way widens a little, its stones cracked in a shallow fan where a side street meets from the north. The remains of a low wall trail off into weeds.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room188",
      "east":"/chapter/prologue/area/ruined/room186",
      "north":"/chapter/prologue/area/ruined/room737",
    ]);

  set_light(1);
}


