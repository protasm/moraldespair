inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Island Historical Society";
    long_desc = "Island Historical Society.\n";
    dest_dir = ({
        "domain/original/area/balin/room664", "south",
        "domain/original/area/balin/room669", "north",
    });
}
