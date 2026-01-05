inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern intersection of Rue du Nord and Kirsch Lane";
    long_desc = "Eastern intersection of Rue du Nord and Kirsch Lane.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room244", "west",
        "domain/original/area/anshelm/room283", "east",
        "domain/original/area/anshelm/room251", "north",
    });
}
