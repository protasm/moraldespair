inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Manor House";
    long_desc = "Manor House.\n";
    dest_dir = ({
        "domain/original/area/vesla/room817", "down",
    });
}
