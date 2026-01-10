inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sundered Hall";
    long_desc = "Sundered Hall";
    dest_dir = ({
        "domain/original/area/vesla/room217", "east",
    });
}
