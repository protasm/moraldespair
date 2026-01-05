inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Via Sacra";
    long_desc = "Via Sacra.\n";
    dest_dir = ({
        "domain/original/area/vesla/room409", "west",
        "domain/original/area/vesla/room218", "south",
        "domain/original/area/vesla/room220", "north",
    });
}
