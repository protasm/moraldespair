inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guild/Shop Space for rent";
    long_desc = "PHASE0: an empty lot for a player-owned business";
    dest_dir = ({
        "domain/original/area/vesla/room172", "west",
    });
}

