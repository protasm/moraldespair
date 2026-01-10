inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Chapel of War";
    long_desc = "Chapel of War";
    dest_dir = ({
        "domain/original/area/vesla/room820", "south",
    });
}
