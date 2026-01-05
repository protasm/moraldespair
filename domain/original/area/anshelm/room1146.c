inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Third Floor Passage";
    long_desc = "Third Floor Passage.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1151", "up",
        "domain/original/area/anshelm/room1145", "west",
    });
}
