inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Anshelmish General Store";
    long_desc = "The Anshelmish General Store.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room251", "west",
    });
}
