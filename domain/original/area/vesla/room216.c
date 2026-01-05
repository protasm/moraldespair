inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Via Sacra";
    long_desc = "Via Sacra.\n";
    dest_dir = ({
        "domain/original/area/vesla/room215", "south",
        "domain/original/area/vesla/room402", "west",
        "domain/original/area/vesla/room403", "east",
        "domain/original/area/vesla/room217", "north",
    });
}
