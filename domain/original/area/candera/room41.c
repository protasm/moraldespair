inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hollow Gap";
    long_desc = "A stub of wall creates a blind corner before the way slips onward. Splintered tiles crunch underfoot, mixed with crushed brick. The silence presses close between the broken walls.";
    dest_dir = ({
        "domain/original/area/candera/room42", "north",
        "domain/original/area/candera/room40", "south",
    });
}
