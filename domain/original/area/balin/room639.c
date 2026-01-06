inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South End of Highland Avenue";
    long_desc = "South End of Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/balin/room638", "east",
        "domain/original/area/balin/room640", "west",
    });
}
