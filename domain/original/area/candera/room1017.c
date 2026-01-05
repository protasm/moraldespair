inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kaimuki Q's";
    long_desc = "Kaimuki Q's.\n";
    dest_dir = ({
        "domain/original/area/candera/room73", "south",
        "domain/original/area/candera/room1018", "west",
    });
}
