inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Caravan Road and Wall Street";
    long_desc = "Intersection of Caravan Road and Wall Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room181", "west",
        "domain/original/area/vesla/room179", "south",
    });
}
