inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East River Street";
    long_desc = "East River Street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room205", "west",
        "domain/original/area/vesla/room207", "east",
        "domain/original/area/vesla/room397", "north",
    });
}
