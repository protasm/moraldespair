inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ashen Ruins";
    long_desc = "Ash lies thick over cracked stone and splintered timbers. The "
        + "air smells of old smoke, and deep gouges show where something "
        + "massive tore through.\n";
    dest_dir = ({
        "domain/original/area/vesla/room800", "south",
    });
}
