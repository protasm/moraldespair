inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Crossing of North Main and Scholar's Way";
    long_desc = "Cracked paving and toppled stones mark where North Main once met Scholar's Way. The junction is choked with rubble and ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room165", "south",
        "domain/original/area/vesla/room192", "east",
        "domain/original/area/vesla/room167", "north",
    });
}
