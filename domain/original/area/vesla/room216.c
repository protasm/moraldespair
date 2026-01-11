inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "A shallow channel cuts along the path, filled with grit and broken tile. The air\n"
                + "is cool and still between the close walls.\n";
    dest_dir = ({
        "domain/original/area/vesla/room215", "south",
        "domain/original/area/vesla/room402", "west",
        "domain/original/area/vesla/room403", "east",
        "domain/original/area/vesla/room217", "north",
    });
}
