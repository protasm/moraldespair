inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "Patches of grass push through the joints in the paving here. The river channel beside the road is choked with debris and still.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room208", "east",
        "chapter/prologue/area/ruined/room206", "west",
    });
}
