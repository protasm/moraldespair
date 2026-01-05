inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Widow's House";
    long_desc = "Widow's House.\n";
    dest_dir = ({
        "domain/original/area/candera/room57", "west",
    });
}
