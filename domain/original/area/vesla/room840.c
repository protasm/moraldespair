inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burned Area";
    long_desc = "Burned Area";
    dest_dir = ({
        "domain/original/area/vesla/room841", "west",
        "domain/original/area/vesla/room148", "south",
    });
}
