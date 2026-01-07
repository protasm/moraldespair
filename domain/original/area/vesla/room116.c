inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Crossing of Two Ruined Roads";
    long_desc = "Burned trees and shattered paving meet here where two ruined roads converge. The air is stale with old smoke and drifting ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room233", "south",
        "domain/original/area/vesla/room117", "west",
        "domain/original/area/vesla/room115", "east",
        "domain/original/area/vesla/room172", "north",
    });
}
