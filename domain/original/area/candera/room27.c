inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "sand-choked lane";
    long_desc = "A wide run of cracked stone stretches north and south, its center scoured to dust. Soot stains cling to the stone, and the air tastes of old smoke.\n\nNo footprints remain; only layered grit records the years.\n";
    dest_dir = ({
        "domain/original/area/candera/room26", "east",
        "domain/original/area/candera/room28", "west",
    });
}
