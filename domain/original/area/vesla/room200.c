inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Crossing of the Bells and Zand Boulevard";
    long_desc = "The crossing is quiet, its stones cracked and coated in ash. No bells ring here now, only the hush of ruin.\n";
    dest_dir = ({
        "domain/original/area/vesla/room201", "west",
        "domain/original/area/vesla/room199", "north",
    });
}
