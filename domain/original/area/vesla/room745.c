inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormitory Kitchen";
    long_desc = "Dormitory Kitchen.\n";
    dest_dir = ({
        "domain/original/area/vesla/room746", "east",
        "domain/original/area/vesla/room741", "south",
    });
}
