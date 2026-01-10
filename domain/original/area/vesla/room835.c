inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Archives";
    long_desc = "City Archives\n";
    dest_dir = ({
        "domain/original/area/vesla/room833", "down",
        "domain/original/area/vesla/room836", "west",
    });
}
