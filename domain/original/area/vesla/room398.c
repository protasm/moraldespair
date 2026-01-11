inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mage's Apprentice House";
    long_desc = "PHASE0: a wizard's home";
    dest_dir = ({
        "domain/original/area/vesla/room397", "west",
    });
}

