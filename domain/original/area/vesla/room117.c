inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Crossing of Two Ruined Streets";
    long_desc = "Charred trunks and broken stones frame the junction of two "
        + "ruined streets. Ash and rubble lie in wind-swept drifts, and "
        + "the stone bears long talon-like scars.\n";
    dest_dir = ({
        "domain/original/area/vesla/room220", "south",
        "domain/original/area/vesla/room118", "west",
        "domain/original/area/vesla/room116", "east",
        "domain/original/area/vesla/room226", "north",
    });
}
