inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wind-Scoured Reach";
    long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit\ncollect in corners, damped by occasional trickles.\n";
    dest_dir = ({
        "domain/original/area/candera/room79", "west",
    });
}
