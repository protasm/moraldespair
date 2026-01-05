inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Viking's room";
    long_desc = "Viking's room.\n";
    dest_dir = ({
        "domain/original/area/vesla/room825", "east",
    });
}
