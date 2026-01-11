inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guild/Shop Space for rent";
    long_desc = "PHASE0: vacant player-owned business lot (available for rent)";
    dest_dir = ({
        "domain/original/area/vesla/room127", "south",
    });
}


