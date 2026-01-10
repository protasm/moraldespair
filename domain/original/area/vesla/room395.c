inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Lathe";
    long_desc = "The Lathe";
    dest_dir = ({
        "domain/original/area/vesla/room209", "south",
    });
}
