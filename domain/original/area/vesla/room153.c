inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Main Road";
    long_desc = "A broad stretch of paving runs north and south, worn smooth in places. The bases\n"
                + "of old walls sit empty, their timbers long gone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room820", "west",
        "domain/original/area/vesla/room152", "south",
        "domain/original/area/vesla/room154", "north",
    });
}
