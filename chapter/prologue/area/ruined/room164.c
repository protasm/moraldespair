inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Road";
    long_desc = "The road passes a doorway choked with rubble and ivy. Small pools of rain-dark water stain the stones.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room163", "south",
        "chapter/prologue/area/ruined/room812", "east",
        "chapter/prologue/area/ruined/room165", "north",
    });
}


