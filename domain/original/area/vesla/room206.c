inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "Silt lies in shallow drifts along the edge of the road. A fallen shutter leans\n"
                + "against the stone, water-dark and warped.\n";
    dest_dir = ({
        "domain/original/area/vesla/room205", "west",
        "domain/original/area/vesla/room207", "east",
        "domain/original/area/vesla/room397", "north",
    });
}
