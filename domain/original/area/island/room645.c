inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven Hut";
    long_desc = "Dwarven Hut.\n";
    dest_dir = ({
        "domain/original/area/island/room644", "south",
    });
}
