inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Arleg bows to you.";
    long_desc = "Arleg bows to you.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1135", "down",
        "domain/original/area/anshelm/room1137", "up",
    });
}
