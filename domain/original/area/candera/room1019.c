inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guild/Shop Space for rent";
    long_desc = "Guild/Shop Space for rent.\n";
    dest_dir = ({
        "domain/original/area/candera/room74", "north",
    });
}
