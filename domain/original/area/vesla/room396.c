inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Strewn Ground";
    long_desc = "Charred fragments litter the ground, and the walls are "
        + "blistered by heat. Long gouges and melted slag mark the "
        + "passing of something huge.\n";
    dest_dir = ({
        "domain/original/area/vesla/room208", "south",
    });
}
