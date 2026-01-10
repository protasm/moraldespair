inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Road";
    long_desc = "Patches of grass push through the joints in the paving\n"
                + "here.\n"
                + "The river channel beside the road is choked with debris\n"
                + "and still.\n";
    dest_dir = ({
        "domain/original/area/vesla/room208", "east",
        "domain/original/area/vesla/room206", "west",
    });
}
