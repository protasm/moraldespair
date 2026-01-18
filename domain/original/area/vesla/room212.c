inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "River Crossing";
    long_desc = "The crossing is a scatter of worn stones, their edges smoothed by time. The two ways meet in silence, framed by damp, crumbling walls.";
    dest_dir = ({
        "domain/original/area/vesla/room211", "west",
        "domain/original/area/vesla/room213", "north",
    });
}
