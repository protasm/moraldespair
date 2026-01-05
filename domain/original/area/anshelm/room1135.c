inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Guard Post";
    long_desc = "Western Guard Post.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1136", "up",
        "domain/original/area/anshelm/room237", "northeast",
    });
}
