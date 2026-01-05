inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern end of Beitel Straad";
    long_desc = "Eastern end of Beitel Straad.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1188", "west",
    });
}
