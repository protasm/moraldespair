inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West River Street";
    long_desc = "West River Street";
    dest_dir = ({
        "domain/original/area/vesla/room146", "east",
        "domain/original/area/vesla/room144", "west",
    });
}
