inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Crowded Thoroughfare";
    long_desc = "Crowded Thoroughfare.\n";
    dest_dir = ({
        "domain/original/area/balin/room724", "south",
        "domain/original/area/balin/room637", "north",
    });
}
