inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Anshelm Stables";
    long_desc = "Anshelm Stables.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room284", "south",
    });
}
