inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Weapon Master's Bedroom";
    long_desc = "Weapon Master's Bedroom\n";
    dest_dir = ({
        "domain/original/area/vesla/room399", "down",
    });
}
