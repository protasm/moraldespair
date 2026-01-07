inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guard Room";
    long_desc = "Guard Room.\n";
    dest_dir = ({
        "domain/original/area/island/room609", "east",
        "domain/original/area/island/room632", "west",
    });
}
