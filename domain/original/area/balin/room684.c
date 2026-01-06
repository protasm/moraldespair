inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hallway";
    long_desc = "Hallway.\n";
    dest_dir = ({
        "domain/original/area/balin/room685", "south",
        "domain/original/area/balin/room679", "north",
    });
}
