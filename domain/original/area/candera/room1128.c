inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Fire";
    long_desc = "Temple of Fire.\n";
    dest_dir = ({
        "domain/original/area/candera/room114", "down",
    });
}
