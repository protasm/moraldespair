inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ground Floor of the Windmill";
    long_desc = "Ground Floor of the Windmill.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room929", "up",
        "domain/original/area/exedoria/room927", "west",
        "domain/original/area/exedoria/room928", "east",
        "domain/original/area/exedoria/room319", "south",
    });
}
