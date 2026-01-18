inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Cots";
    long_desc = "A tight room of empty pallets sits in silence, the straw long gone. Rot has crept up the posts, and the air is stale with old sweat and mildew.";
    dest_dir = ({
        "domain/original/area/vesla/room746", "east",
        "domain/original/area/vesla/room741", "south",
    });
}

