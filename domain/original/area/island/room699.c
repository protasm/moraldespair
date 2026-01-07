inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Harem";
    long_desc = "East Harem.\n";
    dest_dir = ({
        "domain/original/area/island/room700", "east",
        "domain/original/area/island/room698", "west",
    });
}
