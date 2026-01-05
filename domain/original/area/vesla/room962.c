inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Abandoned Store";
    long_desc = "Abandoned Store.\n";
    dest_dir = ({
        "domain/original/area/vesla/room199", "west",
    });
}
