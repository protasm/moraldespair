inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iron Post";
    long_desc = "An iron post rises from the floor, its ring eaten with rust. Chaff and dust cake the ground, and the walls weep with damp.";
    dest_dir = ({
        "domain/original/area/vesla/room773", "south",
    });
}

