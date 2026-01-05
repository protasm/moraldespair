inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to Exedoria";
    long_desc = "Entrance to Exedoria.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room287", "east",
        "domain/original/area/roadway/room28", "exit",
    });
}
