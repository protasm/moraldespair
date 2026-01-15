inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The School of Guild Skills";
    long_desc = "PHASE0: this room allowed players to train and level up their skills related to player-owned businesses (taverns, distillers, armorers, weapons makers, banks, stables, smelters, corpse embalmers)";
    dest_dir = ({
        "domain/original/area/vesla/room189", "north",
    });
}

