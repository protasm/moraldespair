inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "With no gate guard present, you are able to enter the walled estate";
    long_desc = "With no gate guard present, you are able to enter the walled estate.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room342", "south",
        "domain/original/area/exedoria/room351", "north",
    });
}
