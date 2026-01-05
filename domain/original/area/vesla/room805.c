inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Crazy Habib's Fertilizer";
    long_desc = "Crazy Habib's Fertilizer.\n";
    dest_dir = ({
        "domain/original/area/vesla/room802", "north",
    });
}
