inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South End of Highland Avenue";
    long_desc = "South End of Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/island/room638", "east",
        "domain/original/area/island/room640", "west",
    });
}
