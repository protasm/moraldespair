inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to Vesla";
    long_desc = "Entrance to Vesla.\n";
    dest_dir = ({
        "domain/original/area/roadway/room30", "north",
        "domain/original/area/vesla/room134", "city",
    });
}
