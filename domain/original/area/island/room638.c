inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tunnel Under Canal";
    long_desc = "Tunnel Under Canal.\n";
    dest_dir = ({
        "domain/original/area/balin/room637", "east",
        "domain/original/area/balin/room639", "west",
    });
}
