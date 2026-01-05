inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Roof of the Western Spire";
    long_desc = "Roof of the Western Spire.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1139", "down",
    });
}
