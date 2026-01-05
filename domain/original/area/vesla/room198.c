inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Zand Boulevard";
    long_desc = "Zand Boulevard.\n";
    dest_dir = ({
        "domain/original/area/vesla/room199", "south",
        "domain/original/area/vesla/room857", "east",
        "domain/original/area/vesla/room197", "north",
    });
}
