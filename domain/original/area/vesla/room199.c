inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Zand Boulevard";
    long_desc = "Zand Boulevard.\n";
    dest_dir = ({
        "domain/original/area/vesla/room200", "south",
        "domain/original/area/vesla/room962", "east",
        "domain/original/area/vesla/room198", "north",
    });
}
