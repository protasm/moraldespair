inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Barbarian Caves";
    long_desc = "Barbarian Caves.\n";
    dest_dir = ({ });
}
