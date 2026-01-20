inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cobbled Run";
    long_desc = "Cobbles press against the wall here, split by frost and buckling in the soil. Weeds and dark lichen gather where the stonework weeps, muting any echo.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room182", "east",
        "chapter/prologue/area/ruined/room184", "west",
    });
}


