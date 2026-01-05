inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Whore House";
    long_desc = "Whore House.\n";
    dest_dir = ({
        "domain/original/area/vesla/room158", "east",
        "domain/original/area/vesla/room825", "up",
    });
}
