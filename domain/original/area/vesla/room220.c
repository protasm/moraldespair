inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Desecrated Northern End of the Ruined Avenue";
    long_desc = "Charred pillars and shattered altars line the once-holy way. "
        + "The stones are cracked and cold, abandoned for two centuries.\n";
    dest_dir = ({
        "domain/original/area/vesla/room219", "south",
        "domain/original/area/vesla/room221", "west",
        "domain/original/area/vesla/room233", "east",
        "domain/original/area/vesla/room117", "north",
    });
}
