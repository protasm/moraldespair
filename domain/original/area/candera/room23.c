inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "hollow gap";
    long_desc = "A stub of wall creates a blind corner before the way slips onward. Splintered tiles crunch underfoot, mixed with crushed brick.\n\nThe silence presses close between the broken walls.\n";
    dest_dir = ({
        "domain/original/area/candera/room22", "east",
        "domain/original/area/candera/room24", "west",
    });
}
