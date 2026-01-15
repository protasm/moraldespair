inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Littered Pen";
    long_desc = "A pen lies open and collapsed, its boards scattered and softened by\n"
                + "rot. The stone base is stained dark, and the air hangs damp and still.\n";
    dest_dir = ({
        "domain/original/area/vesla/room770", "south",
    });
}

