inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "River Track End";
    long_desc = "The road ends at a tumbled edge of stone, dropping to a\n"
                + "dry, weeded bank.\n"
                + "Broken posts stand like stumps along the rim.\n";
    dest_dir = ({
        "domain/original/area/vesla/room212", "east",
        "domain/original/area/vesla/room210", "west",
    });
}
