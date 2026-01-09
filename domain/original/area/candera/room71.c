inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "eroded rise";
    long_desc = "A jagged seam in the paving marks the line of a sunken run. Ash and grit collect in corners, damped by occasional trickles.\n";
    dest_dir = ({
        "domain/original/area/candera/room69", "west",
    });
}
