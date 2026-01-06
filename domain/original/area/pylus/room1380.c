inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Reliquary";
    long_desc = "Reliquary.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1378", "east",
    });
}
