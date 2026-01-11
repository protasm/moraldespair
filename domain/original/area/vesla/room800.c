inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way\n";
    dest_dir = ({
        "domain/original/area/vesla/room799", "west",
        "domain/original/area/vesla/room801", "east",
        "domain/original/area/vesla/room806", "north",
    });
}
