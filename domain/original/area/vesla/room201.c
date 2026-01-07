inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Bell-Haunted Street";
    long_desc = "Bell towers have fallen and their stones lie strewn across the street. The way is silent, its paving cracked and blackened.\n";
    dest_dir = ({
        "domain/original/area/vesla/room843", "south",
        "domain/original/area/vesla/room202", "west",
        "domain/original/area/vesla/room200", "east",
        "domain/original/area/vesla/room931", "north",
    });
}
