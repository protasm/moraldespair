inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern end of Kirsch Lane";
    long_desc = "Eastern end of Kirsch Lane.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room284", "west",
    });
}
