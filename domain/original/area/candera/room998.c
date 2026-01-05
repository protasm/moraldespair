inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Relic Shop:";
    long_desc = "Relic Shop:.\n";
    dest_dir = ({
        "domain/original/area/candera/room103", "east",
    });
}
