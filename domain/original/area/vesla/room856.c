inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Carvings Shop";
    long_desc = "Carvings Shop";
    dest_dir = ({
        "domain/original/area/vesla/room138", "east",
    });
}
