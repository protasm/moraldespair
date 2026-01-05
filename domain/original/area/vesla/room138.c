inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Basalt Avenue";
    long_desc = "Basalt Avenue.\n";
    dest_dir = ({
        "domain/original/area/vesla/room139", "south",
        "domain/original/area/vesla/room856", "west",
        "domain/original/area/vesla/room855", "east",
        "domain/original/area/vesla/room137", "north",
    });
}
