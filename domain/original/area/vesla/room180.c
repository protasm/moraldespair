inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wallside Crossing";
    long_desc = "The crossing sits in the shadow of the inner wall, where the road\n"
              + "turns and the stones are slick with old runoff. A gutter cuts\n"
              + "across the paving and disappears into rubble.\n";
    dest_dir = ({
        "domain/original/area/vesla/room181", "west",
        "domain/original/area/vesla/room179", "south",
    });
}
