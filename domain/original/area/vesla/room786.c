inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rotted Bays";
    long_desc = "Wide bays open into shadow, their frames softened by decay. Dampness\n"
                + "beads on the stone, and the silence is thick and close.\n";
    dest_dir = ({
        "domain/original/area/vesla/room774", "south",
    });
}

