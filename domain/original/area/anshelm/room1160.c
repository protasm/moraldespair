inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tiran bows to you.";
    long_desc = "Tiran bows to you.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1159", "east",
        "domain/original/area/anshelm/room1161", "west",
    });
}
