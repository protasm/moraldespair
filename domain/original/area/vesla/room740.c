inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallen Annex";
    long_desc = "Fallen Annex";
    dest_dir = ({
        "domain/original/area/vesla/room190", "north",
    });
}
