inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Weapon Master's Bedroom";
    long_desc = "PHASE0: a humble home";
    dest_dir = ({
        "domain/original/area/vesla/room399", "down",
    });
}

