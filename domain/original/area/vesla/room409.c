inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bounty Room";
    long_desc = "PHASE0: players could place and collect bounties on other players here";
    dest_dir = ({
        "domain/original/area/vesla/room219", "east",
    });
}

