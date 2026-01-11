inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Worn Annex";
    long_desc = "A narrow side room lies under a crust of dust, its shelves bowed and the air\n"
        + "stale with mildew. A dry ink smell clings to cracked boxes and a toppled\n"
        + "writing stand, the place long empty.\n";
    dest_dir = ({
        "domain/original/area/vesla/room847", "west",
    });
}
