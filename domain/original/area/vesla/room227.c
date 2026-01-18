inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Overgrown Park";
    long_desc = "Thick grass swallows old benches, leaving warped planks and rusted bolts. A sagging iron fence lists inward, half-buried in leaf mold.";
    dest_dir = ({
        "domain/original/area/vesla/room228", "north",
        "domain/original/area/vesla/room118", "south",
        "domain/original/area/vesla/room226", "east",
        "domain/original/area/vesla/room230", "west",
    });
}


