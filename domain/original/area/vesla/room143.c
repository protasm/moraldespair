inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Corner of Basalt Avenue and West River Street";
    long_desc = "Corner of Basalt Avenue and West River Street";
    dest_dir = ({
        "domain/original/area/vesla/room144", "east",
        "domain/original/area/vesla/room142", "north",
    });
}
