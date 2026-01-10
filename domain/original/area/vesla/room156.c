inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Main Road";
    long_desc = "Broken cobbles gather near a collapsed stoop.\n"
                + "The main road is silent, its centerline marked by a\n"
                + "shallow rut.\n";
    dest_dir = ({
        "domain/original/area/vesla/room155", "south",
        "domain/original/area/vesla/room822", "west",
        "domain/original/area/vesla/room424", "east",
        "domain/original/area/vesla/room157", "north",
    });
}

