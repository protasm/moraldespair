inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A guard house";
    long_desc = "A guard house.\n";
    dest_dir = ({
        "domain/original/area/island/room609", "west",
    });
}
