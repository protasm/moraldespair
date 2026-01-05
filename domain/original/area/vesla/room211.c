inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of East River Street";
    long_desc = "End of East River Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room212", "east",
        "domain/original/area/vesla/room210", "west",
    });
}
