inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Slave quarters";
    long_desc = "Slave quarters.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room915", "east",
    });
}
