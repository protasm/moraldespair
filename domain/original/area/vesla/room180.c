inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Crossing of Caravan Road and Breached Wall Street";
    long_desc = "Rutted Caravan Road meets the shattered wall here, the stones broken into a mound of debris. Ash and rubble choke the crossing.\n";
    dest_dir = ({
        "domain/original/area/vesla/room181", "west",
        "domain/original/area/vesla/room179", "south",
    });
}
