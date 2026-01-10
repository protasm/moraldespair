inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Reconciliation Chapel";
    long_desc = "Reconciliation Chapel";
    dest_dir = ({
        "domain/original/area/vesla/room820", "east",
    });
}
