inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Corridor";
    long_desc = "South Corridor.\n";
    dest_dir = ({
        "domain/original/area/island/room695", "south",
        "domain/original/area/island/room693", "north",
    });
}
