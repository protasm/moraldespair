inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Armoury";
    long_desc = "Armoury.\n";
    dest_dir = ({
        "domain/original/area/island/room631", "east",
        "domain/original/area/island/room633", "west",
    });
}
