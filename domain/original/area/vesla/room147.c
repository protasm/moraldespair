inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "The river road bends past a slumped doorway, its\n"
                + "threshold choked with debris.\n"
                + "Pale lichen maps the stone, and no tracks disturb the\n"
                + "dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room846", "south",
        "domain/original/area/vesla/room146", "west",
        "domain/original/area/vesla/room148", "east",
        "domain/original/area/vesla/room841", "north",
    });
}
