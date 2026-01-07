inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Blistered Stonework";
    long_desc = "Cracked flagstones and soot-smeared walls frame a hollow ruin. Signs of tremendous heat and raking talons remain.\n";
    dest_dir = ({
        "domain/original/area/vesla/room782", "south",
        "domain/original/area/vesla/room775", "west",
        "domain/original/area/vesla/room777", "east",
        "domain/original/area/vesla/room781", "north",
    });
}
