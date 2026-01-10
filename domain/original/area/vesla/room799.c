inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "domain/original/area/vesla/room802", "west",
        "domain/original/area/vesla/room800", "east",
        "domain/original/area/vesla/room798", "south",
    });
}
