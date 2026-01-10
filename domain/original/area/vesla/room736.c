inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guild/Shop Space for rent";
    long_desc = "Guild/Shop Space for rent";
    dest_dir = ({
        "domain/original/area/vesla/room173", "west",
    });
}
