inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Changing room";
    long_desc = "Changing room.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1239", "east",
    });
}
