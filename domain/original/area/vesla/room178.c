inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Scholar's Way and Caravan Road";
    long_desc = "Intersection of Scholar's Way and Caravan Road\n";
    dest_dir = ({
        "domain/original/area/vesla/room185", "west",
        "domain/original/area/vesla/room177", "south",
        "domain/original/area/vesla/room179", "north",
    });
}
