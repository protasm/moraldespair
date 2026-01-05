inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Andre's Clothing";
    long_desc = "Andre's Clothing.\n";
    dest_dir = ({
        "domain/original/area/vesla/room232", "south",
    });
}
