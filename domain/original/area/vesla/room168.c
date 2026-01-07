inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Crossing of North Main and Wall Street";
    long_desc = "The crossing is a churn of broken stone where the wall once stood strong. It is quiet now, a ruin of intersecting streets.\n";
    dest_dir = ({
        "domain/original/area/vesla/room167", "south",
        "domain/original/area/vesla/room793", "west",
        "domain/original/area/vesla/room170", "east",
        "domain/original/area/vesla/room169", "north",
    });
}

void init() {
    add_action("block_structure", "west");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
