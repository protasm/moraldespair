inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruined Passage";
    long_desc = "Ruined Passage.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room251", "west",
    });
}
