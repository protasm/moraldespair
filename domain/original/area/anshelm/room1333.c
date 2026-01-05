inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern statuary";
    long_desc = "Northern statuary.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1330", "south",
    });
}
