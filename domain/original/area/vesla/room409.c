inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bounty Room";
    long_desc = "Bounty Room.\n";
    dest_dir = ({
        "domain/original/area/vesla/room219", "east",
    });
}
