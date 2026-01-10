inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The corner of Westroad and Basalt Avenue";
    long_desc = "The corner of Westroad and Basalt Avenue\n";
    dest_dir = ({
        "domain/original/area/vesla/room134", "west",
        "domain/original/area/vesla/room132", "east",
        "domain/original/area/vesla/room135", "south",
    });
}
