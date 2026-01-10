inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Candle Room";
    long_desc = "Candle Room";
    dest_dir = ({
        "domain/original/area/vesla/room405", "south",
    });
}
