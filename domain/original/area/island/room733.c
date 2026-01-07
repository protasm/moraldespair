inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Administrative hallway";
    long_desc = "Administrative hallway.\n";
    dest_dir = ({
        "domain/original/area/island/room732", "north",
    });
}
