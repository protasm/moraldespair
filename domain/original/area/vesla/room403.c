inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to a temple";
    long_desc = "Entrance to a temple.\n";
    dest_dir = ({
        "domain/original/area/vesla/room404", "east",
        "domain/original/area/vesla/room216", "west",
    });
}
