inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "A long row of broken pillars lines the north side of the way, each stump dark with weathering. The ground is littered with slate chips and fine dust.";
    dest_dir = ({
        "domain/original/area/vesla/room742", "south",
        "domain/original/area/vesla/room192", "west",
        "domain/original/area/vesla/room190", "east",
        "domain/original/area/vesla/room743", "north",
    });
}


