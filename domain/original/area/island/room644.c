inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Highland Avenue";
    long_desc = "Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/island/room643", "south",
        "domain/original/area/island/room646", "west",
        "domain/original/area/island/room648", "east",
        "domain/original/area/island/room645", "north",
    });
}
