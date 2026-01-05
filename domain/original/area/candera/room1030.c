inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Wall Guard Station";
    long_desc = "South Wall Guard Station.\n";
    dest_dir = ({
        "domain/original/area/candera/room29", "north",
        "domain/original/area/candera/room1032", "east",
        "domain/original/area/candera/room1031", "west",
    });
}
