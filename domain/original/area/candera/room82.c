inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "rubble-strewn walk";
    long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.\n";
    dest_dir = ({
        "domain/original/area/candera/room81", "north",
        "domain/original/area/candera/room83", "south",
        "domain/original/area/candera/room1098", "east",
        "domain/original/area/candera/room1097", "west",
    });
}
