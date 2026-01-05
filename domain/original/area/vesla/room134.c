inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western Gate of Vesla";
    long_desc = "Western Gate of Vesla.\n";
    dest_dir = ({
        "domain/original/area/vesla/room133", "east",
        "domain/original/area/roadway/room29", "exit",
    });
}
