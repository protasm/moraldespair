inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guard Post";
    long_desc = "Guard Post.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room384", "south",
        "domain/original/area/exedoria/room292", "north",
    });
}
