inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silt-Choked West Riverside Street";
    long_desc = "The river street is cracked and half-buried beneath silt and "
        + "rubble. Broken embankments, ash, and long gouges show where "
        + "something enormous tore through and wallowed amid the ruins.\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "east",
        "domain/original/area/vesla/room149", "west",
    });
}
