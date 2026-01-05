inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A busy intersection";
    long_desc = "A busy intersection.\n";
    dest_dir = ({
        "domain/original/area/vesla/room159", "south",
        "domain/original/area/vesla/room126", "west",
        "domain/original/area/vesla/room124", "east",
        "domain/original/area/vesla/room160", "north",
    });
}
