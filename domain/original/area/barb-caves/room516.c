inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dark Barricade";
    long_desc = "Dark Barricade.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room517", "east",
        "domain/original/area/barb-caves/room515", "west",
    });
}
