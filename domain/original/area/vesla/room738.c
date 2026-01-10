inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Alley";
    long_desc = "Alley\n";
    dest_dir = ({
        "domain/original/area/vesla/room188", "south",
    });
}
