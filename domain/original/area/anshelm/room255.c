inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Central Square on the Rue du Nord";
    long_desc = "Central Square on the Rue du Nord.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room254", "south",
        "domain/original/area/anshelm/room1195", "west",
        "domain/original/area/anshelm/room1194", "east",
        "domain/original/area/anshelm/room256", "north",
    });
}
