inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern guard quarters";
    long_desc = "Eastern guard quarters.\n";
    dest_dir = ({
        "domain/original/area/vesla/room761", "northeast",
    });
}
