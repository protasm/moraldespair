inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Flat stones lie loose underfoot, some tipped into a shallow rut. A broken lintel rests against a wall, half buried in grit.";
    dest_dir = ({
        "domain/original/area/vesla/room845", "south",
        "domain/original/area/vesla/room145", "west",
        "domain/original/area/vesla/room147", "east",
        "domain/original/area/vesla/room842", "north",
    });
}
