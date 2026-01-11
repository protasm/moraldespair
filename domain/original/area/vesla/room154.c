inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Main Road";
    long_desc = "Thin weeds stripe the main road here, forcing a crooked path. A low curb has\n"
                + "crumbled into the street, leaving a scatter of chips.\n";
    dest_dir = ({
        "domain/original/area/vesla/room153", "south",
        "domain/original/area/vesla/room821", "east",
        "domain/original/area/vesla/room155", "north",
    });
}

