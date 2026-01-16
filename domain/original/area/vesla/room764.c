inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern tower observatory";
    long_desc = "PHASE0: Eastern Tower Observatory";
    dest_dir = ({
        "domain/original/area/vesla/room763", "northeast",
    });
}

