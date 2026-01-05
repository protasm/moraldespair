inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "House of Lord Candera";
    long_desc = "House of Lord Candera.\n";
    dest_dir = ({
        "domain/original/area/candera/room68", "north",
        "domain/original/area/candera/room71", "east",
        "domain/original/area/candera/room70", "west",
        "domain/original/area/candera/room1134", "up",
    });
}
