inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Portal Room";
    long_desc = "Portal Room.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "up",
        "domain/original/area/balin/room605", "island",
        "domain/original/area/preserve/room432", "preserve",
        "domain/original/area/forest/room529", "forest",
    });
}
