inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rue du Nord";
    long_desc = "Rue du Nord.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room256", "south",
        "domain/original/area/anshelm/room258", "north",
    });
}
