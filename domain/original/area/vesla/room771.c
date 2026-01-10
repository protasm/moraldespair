inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The blacksmith";
    long_desc = "The blacksmith";
    dest_dir = ({
        "domain/original/area/vesla/room772", "east",
        "domain/original/area/vesla/room769", "west",
    });
}
