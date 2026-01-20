inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Road";
    long_desc = "The stones are cracked into a ragged mosaic, some sunk low. A rusted hinge hangs from a doorframe, unmoving.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room161", "south",
        "chapter/prologue/area/ruined/room810", "east",
        "chapter/prologue/area/ruined/room163", "north",
    });
}


