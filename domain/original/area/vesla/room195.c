inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rapier Way";
    long_desc = "Rapier Way";
    dest_dir = ({
        "domain/original/area/vesla/room196", "east",
        "domain/original/area/vesla/room194", "west",
    });
}
