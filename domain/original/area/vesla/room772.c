inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The storage room";
    long_desc = "The storage room\n";
    dest_dir = ({
        "domain/original/area/vesla/room771", "west",
    });
}
