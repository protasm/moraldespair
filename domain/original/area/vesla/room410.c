inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dingy alleyway";
    long_desc = "A dingy alleyway";
    dest_dir = ({
        "domain/original/area/vesla/room411", "west",
        "domain/original/area/vesla/room122", "south",
        "domain/original/area/vesla/room792", "north",
    });
}
