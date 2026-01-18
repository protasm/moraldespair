inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Haseltine Engravers";
    long_desc = "Haseltine Engravers";
    dest_dir = ({
        "domain/original/area/vesla/room164", "west",
    });
}
