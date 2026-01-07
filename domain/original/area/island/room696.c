inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "North Corridor";
    long_desc = "North Corridor.\n";
    dest_dir = ({
        "domain/original/area/island/room693", "south",
        "domain/original/area/island/room697", "north",
    });
}
