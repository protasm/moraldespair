inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Rapier Way and Zand Boulevard";
    long_desc = "Intersection of Rapier Way and Zand Boulevard.\n";
    dest_dir = ({
        "domain/original/area/vesla/room196", "west",
        "domain/original/area/vesla/room198", "south",
    });
}
