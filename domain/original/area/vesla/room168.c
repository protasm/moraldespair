inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Crossing of the Northern Main Road and the Wall Road";
    long_desc = "The crossing is a churn of broken stone where the wall once stood strong. It is quiet now, a ruin of intersecting streets.\n";
    dest_dir = ({
        "domain/original/area/vesla/room167", "south",
        "domain/original/area/vesla/room793", "west",
        "domain/original/area/vesla/room170", "east",
        "domain/original/area/vesla/room169", "north",
    });
}

