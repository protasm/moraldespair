inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Excalibur, a closed guild";
    long_desc = "The Excalibur, a closed guild.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room304", "south",
        "domain/original/area/exedoria/room287", "north",
    });
}
