inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The road dips slightly, collecting a shallow sheen of silt from\n"
              + "past rains. Cracked thresholds line both sides, leading into\n"
              + "roofless interiors.\n";
    dest_dir = ({
        "domain/original/area/vesla/room174", "south",
        "domain/original/area/vesla/room176", "north",
    });
}
