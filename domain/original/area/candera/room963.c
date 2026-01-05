inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Entrance";
    long_desc = "Eastern Entrance.\n";
    dest_dir = ({
        "domain/original/area/candera/room57", "east",
        "domain/original/area/candera/room1027", "west",
    });
}
