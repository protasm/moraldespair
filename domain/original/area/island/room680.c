inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hallway";
    long_desc = "Hallway.\n";
    dest_dir = ({
        "domain/original/area/island/room679", "south",
        "domain/original/area/island/room681", "north",
    });
}
