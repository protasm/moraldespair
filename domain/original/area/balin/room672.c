inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple Plaza";
    long_desc = "Temple Plaza.\n";
    dest_dir = ({
        "domain/original/area/balin/room715", "west",
        "domain/original/area/balin/room671", "east",
        "domain/original/area/balin/room662", "south",
    });
}
