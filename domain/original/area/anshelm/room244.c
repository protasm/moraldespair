inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western intersection of Rue du Nord and Kirsch Lane";
    long_desc = "Western intersection of Rue du Nord and Kirsch Lane.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room245", "west",
        "domain/original/area/anshelm/room250", "east",
        "domain/original/area/anshelm/room243", "south",
    });
}
