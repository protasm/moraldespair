inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Crack of Doom";
    long_desc = "Crack of Doom.\n";
    dest_dir = ({
        "domain/original/area/island/room686", "up",
    });
}
