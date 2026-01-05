inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Crypt of the Honored Dead";
    long_desc = "Crypt of the Honored Dead.\n";
    dest_dir = ({
        "domain/original/area/candera/room82", "west",
        "domain/original/area/candera/room1099", "down",
    });
}
