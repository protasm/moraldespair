inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Splintered Rapier Way";
    long_desc = "The paving is slashed and splintered, as if a blade had carved through stone. The dragons' assault left this way broken and lifeless.\n";
    dest_dir = ({
        "domain/original/area/vesla/room194", "east",
        "domain/original/area/vesla/room137", "west",
    });
}
