inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Island Historical Society";
    long_desc = "Island Historical Society.\n";
    dest_dir = ({
        "domain/original/area/island/room664", "south",
        "domain/original/area/island/room669", "north",
    });
}
