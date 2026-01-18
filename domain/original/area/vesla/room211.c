inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "River Track End";
    long_desc = "The road ends at a tumbled edge of stone, dropping to a dry, weeded bank. Broken posts stand like stumps along the rim.";
    dest_dir = ({
        "domain/original/area/vesla/room212", "east",
        "domain/original/area/vesla/room210", "west",
    });
}
