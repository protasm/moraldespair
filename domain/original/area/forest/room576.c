inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The start of a forest path";
    long_desc = "The start of a forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room577", "southwest",
        "domain/original/area/forest/room551", "north",
    });
}
