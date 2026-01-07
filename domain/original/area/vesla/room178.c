inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Crossing of a Quiet Lane and the Trade Road";
    long_desc = "Broken paving and gouged stone meet where a trade route crosses a quiet lane. The junction is littered with debris and ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room185", "west",
        "domain/original/area/vesla/room177", "south",
        "domain/original/area/vesla/room179", "north",
    });
}
