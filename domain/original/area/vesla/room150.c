inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West River street";
    long_desc = "West River street\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "east",
        "domain/original/area/vesla/room149", "west",
    });
}
