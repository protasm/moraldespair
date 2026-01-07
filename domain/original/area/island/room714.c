inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Central Chamber";
    long_desc = "Central Chamber.\n";
    dest_dir = ({
        "domain/original/area/island/room715", "east",
        "domain/original/area/island/room713", "west",
    });
}
