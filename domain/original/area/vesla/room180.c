inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Crossing of the Trade Road and the Wall Road";
    long_desc = "A rutted trade road meets the shattered wall here, the stones broken into a mound of debris. Ash and rubble choke the crossing.\n";
    dest_dir = ({
        "domain/original/area/vesla/room181", "west",
        "domain/original/area/vesla/room179", "south",
    });
}
