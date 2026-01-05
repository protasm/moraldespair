inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Jusonah's Pawn and Polearms";
    long_desc = "Jusonah's Pawn and Polearms.\n";
    dest_dir = ({
        "domain/original/area/indel/room1404", "east",
    });
}
