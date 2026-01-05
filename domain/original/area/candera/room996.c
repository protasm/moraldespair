inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Candera Priest's Hut";
    long_desc = "Candera Priest's Hut.\n";
    dest_dir = ({
        "domain/original/area/candera/room111", "west",
    });
}
