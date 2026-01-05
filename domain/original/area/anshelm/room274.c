inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Under the Town Gate";
    long_desc = "Under the Town Gate.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room273", "south",
        "domain/original/area/anshelm/room275", "north",
    });
}
