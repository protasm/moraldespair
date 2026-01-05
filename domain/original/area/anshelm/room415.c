inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Club Femme Nu";
    long_desc = "Club Femme Nu.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room240", "east",
        "domain/original/area/anshelm/room414", "south",
    });
}
