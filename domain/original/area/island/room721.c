inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road Pub";
    long_desc = "Balin Road Pub.\n";
    dest_dir = ({
        "domain/original/area/island/room636", "northwest",
    });
}
