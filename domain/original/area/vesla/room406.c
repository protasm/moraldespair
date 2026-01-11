inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Candle Room";
    long_desc = "PHASE0: a temple of worship";
    dest_dir = ({
        "domain/original/area/vesla/room405", "south",
    });
}

