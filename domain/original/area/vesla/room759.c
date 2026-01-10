inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern guard room";
    long_desc = "Eastern guard room\n";
    dest_dir = ({
        "domain/original/area/vesla/room760", "northeast",
        "domain/original/area/vesla/room758", "north",
    });
}
