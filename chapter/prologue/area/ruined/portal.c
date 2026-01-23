inherit "room/room";

void create() {
  ::create();

    short_desc = "Portal Room";
    long_desc = "This is the portal room. As development continues, these areas will be removed from the portal room and linked to the full world.";
    dest_dir = ([
      "up":"/chapter/prologue/area/ruined/sanctuary",
      "island":"/chapter/prologue/area/island/room605",
      "preserve":"/domain/original/area/preserve/room432",
      "forest":"/domain/original/area/forest/room529",
      "pylus":"/domain/original/area/pylus/room1205",
      "green":"/domain/original/area/village-green/room1687",
      "caves":"/domain/original/area/barb-caves/room515",
    ]);

  set_light(1);
}
