inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of the builders guild";
    long_desc = "Hall of the builders guild.\n";
    dest_dir = ({
        "domain/original/area/vesla/room154", "west",
    });
}
