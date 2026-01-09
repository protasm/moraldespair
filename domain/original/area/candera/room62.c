inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "wind-scoured reach";
    long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.\n";
    dest_dir = ({
        "domain/original/area/candera/room61", "north",
        "domain/original/area/candera/room63", "south",
        "domain/original/area/candera/room972", "east",
        "domain/original/area/candera/room971", "west",
    });
}
