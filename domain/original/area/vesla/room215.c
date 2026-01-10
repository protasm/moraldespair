inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Via Sacra";
    long_desc = "Via Sacra";
    dest_dir = ({
        "domain/original/area/vesla/room214", "south",
        "domain/original/area/vesla/room216", "north",
    });
}
