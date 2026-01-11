inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pornographers Den";
    long_desc = "PHASE0: pornography den with an aggressive NPC";
    dest_dir = ({
        "domain/original/area/vesla/room802", "south",
    });
}

