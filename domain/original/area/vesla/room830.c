inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Baker's Shop";
    long_desc = "Baker's Shop";
    dest_dir = ({
        "domain/original/area/vesla/room157", "west",
    });
}
