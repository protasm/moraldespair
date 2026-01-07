inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Players' Lounge";
    long_desc = "This is the players' lounge.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "down",
    });
}
