inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Wall Guard Station";
    long_desc = "South Wall Guard Station.\n";
    dest_dir = ({
        "domain/original/area/candera/room1030", "south",
        "domain/original/area/candera/room28", "east",
        "domain/original/area/candera/room30", "west",
    });
}
