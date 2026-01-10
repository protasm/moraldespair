inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Flea Market";
    long_desc = "Flea Market";
    dest_dir = ({
        "domain/original/area/vesla/room796", "north",
    });
}
