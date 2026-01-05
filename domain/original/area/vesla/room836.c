inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Inner Sanctum";
    long_desc = "Inner Sanctum.\n";
    dest_dir = ({
        "domain/original/area/vesla/room835", "east",
    });
}
