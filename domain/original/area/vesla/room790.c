inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You swing open the wooden door and enter the stall.";
    long_desc = "You swing open the wooden door and enter the stall.";
    dest_dir = ({
        "domain/original/area/vesla/room770", "north",
    });
}
