inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Church Road and Embassy Row";
    long_desc = "Intersection of Church Road and Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1543", "north",
        "domain/original/area/indel/room1547", "east",
        "domain/original/area/indel/room1545", "west",
    });
}
