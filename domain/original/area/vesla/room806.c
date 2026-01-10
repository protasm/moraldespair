inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Barber Shop";
    long_desc = "Barber Shop";
    dest_dir = ({
        "domain/original/area/vesla/room800", "south",
    });
}
