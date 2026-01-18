inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "The paving is patched with mismatched stones, as if repairs once stalled here. A low mound of rubble spills from the west, half blocking the way before the crossing.";
    dest_dir = ({
        "domain/original/area/vesla/room176", "south",
        "domain/original/area/vesla/room178", "north",
    });
}
