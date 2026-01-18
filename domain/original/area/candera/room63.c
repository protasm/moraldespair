inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rubble-Strewn Walk";
    long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
    dest_dir = ({
        "domain/original/area/candera/room62", "north",
        "domain/original/area/candera/room64", "south",
        "domain/original/area/candera/room94", "east",
        "domain/original/area/candera/room72", "west",
    });
}
