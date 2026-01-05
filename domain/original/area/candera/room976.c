inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Back Alley";
    long_desc = "Back Alley.\n";
    dest_dir = ({
        "domain/original/area/candera/room96", "north",
    });
}
