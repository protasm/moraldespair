inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to the Northwest Tower";
    long_desc = "Entrance to the Northwest Tower.\n";
    dest_dir = ({
        "domain/original/area/candera/room52", "east",
        "domain/original/area/candera/room50", "west",
    });
}
