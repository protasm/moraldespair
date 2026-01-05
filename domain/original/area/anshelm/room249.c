inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Kaneohe Armory";
    long_desc = "Kaneohe Armory.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room246", "north",
    });
}
