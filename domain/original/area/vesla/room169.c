inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern Gate";
    long_desc = "PHASE0: Northern Gate";
    dest_dir = ({
        "domain/original/area/vesla/room168", "south",
        "domain/original/area/vesla/room753", "northeast",
    });
}


