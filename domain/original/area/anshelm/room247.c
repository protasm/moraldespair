inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western end of Kirsch Lane";
    long_desc = "Western end of Kirsch Lane.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room246", "east",
        "domain/original/area/anshelm/room248", "south",
    });
}
