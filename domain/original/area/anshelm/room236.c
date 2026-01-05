inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Under the Anshelmish Gatehouse";
    long_desc = "Under the Anshelmish Gatehouse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1143", "west",
        "domain/original/area/anshelm/room235", "south",
        "domain/original/area/anshelm/room237", "north",
    });
}
