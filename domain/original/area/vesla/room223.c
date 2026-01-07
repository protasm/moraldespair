inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Vault";
    long_desc = "A cold hush hangs over the wreckage. Scorched beams and soot-blackened stone suggest flames that once raged here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room224", "west",
        "domain/original/area/vesla/room222", "east",
        "domain/original/area/vesla/room120", "north",
    });
}
