inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Rabbit's Hole";
    long_desc = "The Rabbit's Hole.\n";
    dest_dir = ({
        "domain/original/area/candera/room94", "north",
        "domain/original/area/candera/room64", "west",
    });
}
