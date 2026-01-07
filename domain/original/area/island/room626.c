inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruins";
    long_desc = "Ruins.\n";
    dest_dir = ({
        "domain/original/area/island/room627", "east",
        "domain/original/area/island/room606", "west",
    });
}
