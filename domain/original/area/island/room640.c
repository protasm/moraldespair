inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Highland Avenue";
    long_desc = "Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/island/room657", "south",
        "domain/original/area/island/room639", "east",
        "domain/original/area/island/room641", "north",
    });
}
