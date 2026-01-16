inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wash area";
    long_desc = "PHASE0: stable wash area";
    dest_dir = ({
        "domain/original/area/vesla/room778", "southeast",
        "domain/original/area/vesla/room777", "south",
    });
}

