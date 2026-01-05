inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Busy Kitchen";
    long_desc = "Busy Kitchen.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room352", "south",
    });
}
