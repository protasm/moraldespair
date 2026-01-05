inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Park Street and Caravan Road";
    long_desc = "Intersection of Park Street and Caravan Road.\n";
    dest_dir = ({
        "domain/original/area/vesla/room233", "south",
        "domain/original/area/vesla/room117", "west",
        "domain/original/area/vesla/room115", "east",
        "domain/original/area/vesla/room172", "north",
    });
}
