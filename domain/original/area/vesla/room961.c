inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rising Phoenix";
    long_desc = "Rising Phoenix.\n";
    dest_dir = ({
        "domain/original/area/vesla/room796", "south",
    });
}
