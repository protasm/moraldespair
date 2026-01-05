inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Magoo's Bookstore";
    long_desc = "Magoo's Bookstore.\n";
    dest_dir = ({
        "domain/original/area/vesla/room191", "north",
    });
}
