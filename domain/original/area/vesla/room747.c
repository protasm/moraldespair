inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormitory Administrator's Room";
    long_desc = "Dormitory Administrator's Room.\n";
    dest_dir = ({
        "domain/original/area/vesla/room741", "west",
    });
}
