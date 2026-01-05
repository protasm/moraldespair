inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Olotia bows to you.";
    long_desc = "Olotia bows to you.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1158", "down",
        "domain/original/area/anshelm/room1160", "west",
    });
}
