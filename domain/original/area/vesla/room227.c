inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park";
    dest_dir = ({
        "domain/original/area/vesla/room228", "north",
        "domain/original/area/vesla/room118", "south",
        "domain/original/area/vesla/room226", "east",
        "domain/original/area/vesla/room230", "west",
    });
}
