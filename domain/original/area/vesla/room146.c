inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West River Street";
    long_desc = "West River Street\n";
    dest_dir = ({
        "domain/original/area/vesla/room845", "south",
        "domain/original/area/vesla/room145", "west",
        "domain/original/area/vesla/room147", "east",
        "domain/original/area/vesla/room842", "north",
    });
}
