inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Main street";
    long_desc = "South Main street";
    dest_dir = ({
        "domain/original/area/vesla/room824", "west",
        "domain/original/area/vesla/room157", "south",
        "domain/original/area/vesla/room159", "north",
    });
}
