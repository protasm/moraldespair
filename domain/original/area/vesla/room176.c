inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Caravan Road";
    long_desc = "Caravan Road\n";
    dest_dir = ({
        "domain/original/area/vesla/room175", "south",
        "domain/original/area/vesla/room177", "north",
    });
}
