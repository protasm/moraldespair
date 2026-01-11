inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Portal Room";
    long_desc = "This is the portal room. As development continues, these areas will be removed\n"
                + "from the portal room and linked to the full world.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "up",
        "domain/original/area/island/room605", "island",
        "domain/original/area/preserve/room432", "preserve",
        "domain/original/area/forest/room529", "forest",
        "domain/original/area/pylus/room1205", "pylus",
        "domain/original/area/village-green/room1687", "green",
        "domain/original/area/barb-caves/room515", "caves",
    });
}
