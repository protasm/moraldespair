inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The School of Guild Skills";
    long_desc = "The School of Guild Skills";
    dest_dir = ({
        "domain/original/area/vesla/room189", "north",
    });
}
