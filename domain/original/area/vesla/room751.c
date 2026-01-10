inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormer";
    long_desc = "Dormer\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "east",
    });
}
