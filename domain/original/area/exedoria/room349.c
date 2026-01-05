inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Snowy cave";
    long_desc = "Snowy cave.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room348", "north",
    });
}
