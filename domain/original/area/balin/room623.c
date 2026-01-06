inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Part of Beach";
    long_desc = "Western Part of Beach.\n";
    dest_dir = ({
        "domain/original/area/balin/room606", "east",
        "domain/original/area/balin/room624", "west",
    });
}
