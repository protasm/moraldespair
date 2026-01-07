inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keep Of Alcibiades";
    long_desc = "Keep Of Alcibiades.\n";
    dest_dir = ({
        "domain/original/area/balin/room659", "west",
        "domain/original/area/balin/room658", "east",
        "domain/original/area/balin/room640", "north",
    });
}
