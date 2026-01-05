inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Effortlessly, you scale the brick wall and drop into a garden on the opposite";
    long_desc = "Effortlessly, you scale the brick wall and drop into a garden on the opposite.\n";
    dest_dir = ({
        "domain/original/area/vesla/room168", "east",
    });
}
