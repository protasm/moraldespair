inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Vault";
    long_desc = "A cold hush hangs over the wreckage. Scorched beams and "
        + "soot-blackened stone suggest flames that once raged here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room841", "west",
        "domain/original/area/vesla/room148", "south",
    });
}
