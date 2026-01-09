inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Splintered Narrow Way";
    long_desc = "The paving is slashed and splintered, as if a blade had carved"
        + " through stone. Scorched ruts and scattered bones leave the "
        + "way broken and lifeless.\n";
    dest_dir = ({
        "domain/original/area/vesla/room196", "east",
        "domain/original/area/vesla/room194", "west",
    });
}
