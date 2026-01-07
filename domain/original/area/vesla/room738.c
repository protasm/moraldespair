inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Choked Alley";
    long_desc = "The alley is little more than a trench of shattered stone and collapsed timbers. Ash and rubble fill the cramped passage.\n";
    dest_dir = ({
        "domain/original/area/vesla/room188", "south",
    });
}
