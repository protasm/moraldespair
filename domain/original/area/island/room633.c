inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Elderoak's Quarters";
    long_desc = "Elderoak's Quarters.\n";
    dest_dir = ({
        "domain/original/area/island/room632", "east",
    });
}
