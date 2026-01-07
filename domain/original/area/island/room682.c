inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Council Chamber";
    long_desc = "Council Chamber.\n";
    dest_dir = ({
        "domain/original/area/balin/room681", "east",
        "domain/original/area/balin/room683", "west",
    });
}
