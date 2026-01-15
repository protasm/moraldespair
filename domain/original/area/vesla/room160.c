inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Main Road";
    long_desc = "The northward main road rises slightly, its stones pale and chipped. A cold\n"
              + "breeze funnels through the gap between empty facades.\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "south",
        "domain/original/area/vesla/room412", "east",
        "domain/original/area/vesla/room161", "north",
    });
}
