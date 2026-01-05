inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible";
    long_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room290", "south",
    });
}
