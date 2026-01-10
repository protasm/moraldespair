inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Players' lounge";
    long_desc = "The Players' lounge\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "down",
    });
}
