inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keen Street West";
    long_desc = "Keen Street West.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room335", "east",
    });
}
