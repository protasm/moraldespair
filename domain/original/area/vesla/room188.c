inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silent Way";
    long_desc = "Fragments of carved stone lie half-buried along the edges of the lane, their markings softened by time. A faint ridge of sand has collected against the eastern curb.";
    dest_dir = ({
        "domain/original/area/vesla/room189", "west",
        "domain/original/area/vesla/room187", "east",
        "domain/original/area/vesla/room738", "north",
    });
}


