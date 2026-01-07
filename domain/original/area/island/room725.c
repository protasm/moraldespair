inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bazaar Crossroad";
    long_desc = "Bazaar Crossroad.\n";
    dest_dir = ({
        "domain/original/area/island/room726", "west",
        "domain/original/area/island/room729", "east",
        "domain/original/area/island/room724", "north",
    });
}
