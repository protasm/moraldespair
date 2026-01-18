inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Road";
    long_desc = "The stones are cracked into a ragged mosaic, some sunk low. A rusted hinge hangs from a doorframe, unmoving.";
    dest_dir = ({
        "domain/original/area/vesla/room161", "south",
        "domain/original/area/vesla/room810", "east",
        "domain/original/area/vesla/room163", "north",
    });
}


