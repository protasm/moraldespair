inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Abandoned Park";
    long_desc = "A once-open lawn is now a tangle of thorn and nettle. Broken edging stones ring the growth like a half-lost border.";
    dest_dir = ({
        "domain/original/area/vesla/room119", "south",
        "domain/original/area/vesla/room815", "west",
        "domain/original/area/vesla/room227", "east",
        "domain/original/area/vesla/room231", "north",
    });
}
