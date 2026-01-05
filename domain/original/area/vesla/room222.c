inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Comfortably Numb";
    long_desc = "Comfortably Numb.\n";
    dest_dir = ({
        "domain/original/area/vesla/room223", "west",
        "domain/original/area/vesla/room221", "east",
        "domain/original/area/vesla/room119", "north",
    });
}
