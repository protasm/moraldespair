inherit "room/room";

void create() {
  ::create();

    short_desc = "Portal Room";
    long_desc = "This is the portal room. As development continues, these areas will be removed from the portal room and linked to the full world.";
    dest_dir = ({
        "chapter/prologue/area/ruined/sanctuary", "up",
        "domain/original/area/island/room605", "island",
        "domain/original/area/preserve/room432", "preserve",
        "domain/original/area/forest/room529", "forest",
        "domain/original/area/pylus/room1205", "pylus",
        "domain/original/area/village-green/room1687", "green",
        "domain/original/area/barb-caves/room515", "caves",
    });

  set_light(1);
}
