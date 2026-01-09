inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "wind-scoured reach";
    long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.\n";
    dest_dir = ({
        "domain/original/area/candera/room80", "north",
        "domain/original/area/candera/room82", "south",
    });
}
