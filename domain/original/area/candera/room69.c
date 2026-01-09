inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "tumbled slope";
    long_desc = "A short rise of uneven paving leads to a wind-carved platform. Rust-red streaks mark where metal once lay, now long gone.\n\nThe ground bears the weight of repeated collapse.\n";
    dest_dir = ({
        "domain/original/area/candera/room68", "north",
        "domain/original/area/candera/room71", "east",
        "domain/original/area/candera/room70", "west",
        "domain/original/area/candera/room1134", "up",
    });
}
