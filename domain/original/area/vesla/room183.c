inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cobbled Run";
    long_desc = "Cobbles press against the wall here, split by frost and buckling in\n"
                + "the soil. Weeds and dark lichen gather where the stonework weeps,\n"
                + "muting any echo.\n";
    dest_dir = ({
        "domain/original/area/vesla/room182", "east",
        "domain/original/area/vesla/room184", "west",
    });
}


