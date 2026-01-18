inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Stretch";
    long_desc = "The path angles around a heap of fallen blocks, forcing a slow turn. Hollow window frames stare out, their ledges buried in dust. The wind slides through with a dry hiss.";
    dest_dir = ({
        "domain/original/area/candera/room33", "east",
        "domain/original/area/candera/room35", "west",
    });
}
