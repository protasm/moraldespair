inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gate to the Village Green";
    long_desc = "Gate to the Village Green.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1693", "east",
        "domain/original/area/village-green/room1688", "south",
        "domain/original/area/vesla/portal", "vesla",
    });
}
