inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mess Hall";
    long_desc = "Mess Hall.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room523", "south",
    });
}
