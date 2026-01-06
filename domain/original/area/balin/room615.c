inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/balin/room688", "west",
        "domain/original/area/balin/room614", "south",
        "domain/original/area/balin/room616", "north",
    });
}
