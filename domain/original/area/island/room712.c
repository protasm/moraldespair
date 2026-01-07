inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hermit's Chamber";
    long_desc = "Hermit's Chamber.\n";
    dest_dir = ({
        "domain/original/area/island/room655", "east",
    });
}
