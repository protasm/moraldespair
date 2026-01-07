inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Armoury";
    long_desc = "Armoury.\n";
    dest_dir = ({
        "domain/original/area/balin/room631", "east",
        "domain/original/area/balin/room633", "west",
    });
}
