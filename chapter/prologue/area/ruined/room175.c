inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road dips slightly, collecting a shallow sheen of silt from past rains. Cracked thresholds line both sides, leading into roofless interiors.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room174", "south",
        "chapter/prologue/area/ruined/room176", "north",
    });
}
