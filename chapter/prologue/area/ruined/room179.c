inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road straightens and grows bare, its center rutted by the ghost of old traffic. A broken post leans beside a gap where a shopfront has collapsed.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room178", "south",
        "chapter/prologue/area/ruined/room180", "north",
    });
}
