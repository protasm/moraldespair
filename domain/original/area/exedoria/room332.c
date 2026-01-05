inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Exedorian saloon";
    long_desc = "Exedorian saloon.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room331", "east",
    });
}
