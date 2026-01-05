inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Infirmary";
    long_desc = "Infirmary.\n";
    dest_dir = ({
        "domain/original/area/indel/room1600", "north",
        "domain/original/area/indel/room1605", "east",
    });
}
