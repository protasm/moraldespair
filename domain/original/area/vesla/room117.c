inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Crossing of Park Street and Via Sacra";
    long_desc = "Charred trunks and broken stones frame the junction of Park Street and the Via Sacra. Only ash and rubble remain where the dragons swept through.\n";
    dest_dir = ({
        "domain/original/area/vesla/room220", "south",
        "domain/original/area/vesla/room118", "west",
        "domain/original/area/vesla/room116", "east",
        "domain/original/area/vesla/room226", "north",
    });
}
