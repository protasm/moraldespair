inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Third Floor Passage";
    long_desc = "Third Floor Passage.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1137", "down",
        "domain/original/area/anshelm/room1144", "east",
        "domain/original/area/anshelm/room1139", "up",
    });
}
