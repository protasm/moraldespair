inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Crossing of Basalt Avenue and Rapier Way";
    long_desc = "Melted basalt and splintered cobbles meet where the avenues cross. The junction is a smear of slag and rubble.\n";
    dest_dir = ({
        "domain/original/area/vesla/room138", "south",
        "domain/original/area/vesla/room193", "east",
        "domain/original/area/vesla/room136", "north",
    });
}
