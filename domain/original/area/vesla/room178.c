inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Crossing of Scholar's Way and Caravan Road";
    long_desc = "Broken paving and gouged stone meet where the caravan route crosses Scholar's Way. The junction is littered with debris and ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room185", "west",
        "domain/original/area/vesla/room177", "south",
        "domain/original/area/vesla/room179", "north",
    });
}
