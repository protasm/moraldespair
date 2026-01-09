inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "tumbled slope";
    long_desc = "A short rise of uneven paving leads to a wind-carved platform. Rust-red streaks mark where metal once lay, now long gone.\n\nThe ground bears the weight of repeated collapse.\n";
    dest_dir = ({
        "domain/original/area/candera/room100", "east",
    });
}
