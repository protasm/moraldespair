inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bedroom:";
    long_desc = "Bedroom:.\n";
    dest_dir = ({
        "domain/original/area/island/room657", "east",
    });
}
