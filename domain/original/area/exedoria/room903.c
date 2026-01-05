inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Resident Advisor's office";
    long_desc = "Resident Advisor's office.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room894", "south",
    });
}
