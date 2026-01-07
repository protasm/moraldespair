inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Keep Of Alcibiades";
    long_desc = "Keep Of Alcibiades.\n";
    dest_dir = ({
        "domain/original/area/island/room659", "west",
        "domain/original/area/island/room658", "east",
        "domain/original/area/island/room640", "north",
    });
}
