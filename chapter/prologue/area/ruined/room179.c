inherit "room/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "The road straightens and grows bare, its center rutted by the ghost of old traffic. A broken post leans beside a gap where a shopfront has collapsed.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room178",
      "north":"/chapter/prologue/area/ruined/room180",
    ]);

  set_light(1);
}
