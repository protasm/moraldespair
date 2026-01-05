inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Altar of the Rose";
    long_desc = "Altar of the Rose.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1330", "west",
    });
}
