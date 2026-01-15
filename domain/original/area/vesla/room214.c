inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Southern Cracked Way";
    long_desc = "Wide paving slabs lie buckled and parted by grass. A line of soot-streaked\n"
              + "stone posts leans in slow collapse.\n";
    dest_dir = ({
        "domain/original/area/vesla/room213", "south",
        "domain/original/area/vesla/room400", "west",
        "domain/original/area/vesla/room401", "east",
        "domain/original/area/vesla/room215", "north",
    });
}
