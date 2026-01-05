inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Roof of the Eastern Spire";
    long_desc = "Roof of the Eastern Spire.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1151", "down",
    });
}
