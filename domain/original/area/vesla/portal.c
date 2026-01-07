inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Portal Room";
    long_desc = "Portal Room.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "up",
        "domain/original/area/island/room605", "island",
        "domain/original/area/preserve/room432", "preserve",
        "domain/original/area/forest/room529", "forest",
        "domain/original/area/pylus/room1205", "pylus",
        "domain/original/area/village-green/room1687", "green",
    });
}
