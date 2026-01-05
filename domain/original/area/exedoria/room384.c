inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beginning of Brapnor Road";
    long_desc = "Beginning of Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room385", "west",
        "domain/original/area/exedoria/room386", "southeast",
        "domain/original/area/exedoria/room383", "north",
    });
}
