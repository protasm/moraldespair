inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash-Choked Crossing of Two Ruined Boulevards";
    long_desc = "Ash drifts over the crossing, softening the edges of shattered cobbles. The ruined streets meet in a haze of gray dust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room196", "west",
        "domain/original/area/vesla/room198", "south",
    });
}
