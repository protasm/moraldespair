inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Chamber of Commerce";
    long_desc = "Chamber of Commerce.\n";
    dest_dir = ({
        "domain/original/area/vesla/room187", "south",
    });
}
