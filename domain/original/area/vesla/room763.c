inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Upper eastern stairwell";
    long_desc = "Upper eastern stairwell\n";
    dest_dir = ({
        "domain/original/area/vesla/room764", "southwest",
        "domain/original/area/vesla/room761", "down",
    });
}
