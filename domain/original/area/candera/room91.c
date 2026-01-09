inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hollow Gap";
    long_desc = "A stub of wall creates a blind corner before the way slips onward. Splintered\ntiles crunch underfoot, mixed with crushed brick.\n\nThe silence presses close between the broken walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room90", "south",
        "domain/original/area/candera/room93", "east",
        "domain/original/area/candera/room92", "west",
    });
}
