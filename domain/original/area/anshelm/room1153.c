inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tider bows to you.";
    long_desc = "Tider bows to you.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1142", "west",
    });
}
