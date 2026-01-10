inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stationery Store";
    long_desc = "Stationery Store";
    dest_dir = ({
        "domain/original/area/vesla/room190", "north",
    });
}
