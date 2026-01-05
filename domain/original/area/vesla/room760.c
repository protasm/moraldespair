inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lower eastern stairwell";
    long_desc = "Lower eastern stairwell.\n";
    dest_dir = ({
        "domain/original/area/vesla/room759", "southwest",
        "domain/original/area/vesla/room761", "up",
    });
}
