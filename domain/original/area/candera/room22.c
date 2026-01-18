inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eroded Rise";
    long_desc = "A jagged seam in the paving marks the line of a sunken run. Ash and grit collect in corners, damped by occasional trickles.";
    dest_dir = ({
        "domain/original/area/candera/room21", "north",
        "domain/original/area/candera/room23", "west",
    });
}
