inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "MD Banking";
    long_desc = "PHASE0: a player-owned guild (bank)";
    dest_dir = ({
        "domain/original/area/vesla/room217", "east",
    });
}


