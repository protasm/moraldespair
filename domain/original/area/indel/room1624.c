inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Saul's formal wear";
    long_desc = "Saul's formal wear.\n";
    dest_dir = ({
        "domain/original/area/indel/room1509", "south",
    });
}
