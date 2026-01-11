inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "East River Track";
    long_desc = "The eastern stretch runs straight and hollow, its stones slick with moss. A low\n"
                + "wall beside it is buckled and split.\n";
    dest_dir = ({
        "domain/original/area/vesla/room206", "east",
        "domain/original/area/vesla/room151", "west",
    });
}
