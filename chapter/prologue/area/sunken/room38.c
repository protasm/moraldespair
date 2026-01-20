inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tumbled Slope";
    long_desc = "A short rise of uneven paving leads to a wind-carved platform. Rust-red streaks mark where metal once lay, now long gone. The ground bears the weight of repeated collapse.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room39", "north",
        "chapter/prologue/area/sunken/room37", "south",
    });
}
