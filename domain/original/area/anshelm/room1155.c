inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ganran bows to you.";
    long_desc = "Ganran bows to you.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1158", "up",
        "domain/original/area/anshelm/room1156", "down",
        "domain/original/area/anshelm/room1154", "west",
    });
}
