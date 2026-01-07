inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Basalt Avenue";
    long_desc = "Basalt blocks are cracked and glassy, fused by searing heat. The avenue runs like a blackened scar through the ruins.\n";
    dest_dir = ({
        "domain/original/area/vesla/room143", "south",
        "domain/original/area/vesla/room850", "east",
        "domain/original/area/vesla/room141", "north",
    });
}
