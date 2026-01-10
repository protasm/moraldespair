inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dark alleyway";
    long_desc = "A dark alleyway\n";
    dest_dir = ({
        "domain/original/area/vesla/room129", "north",
    });
}
