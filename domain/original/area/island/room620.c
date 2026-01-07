inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Island smeltery";
    long_desc = "Island smeltery.\n";
    dest_dir = ({
        "domain/original/area/balin/room621", "east",
        "domain/original/area/balin/room619", "west",
    });
}
