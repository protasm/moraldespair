inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to the Old City.";
    long_desc = "Entrance to the Old City.\n";
    dest_dir = ({
        "domain/original/area/vesla/room128", "west",
        "domain/original/area/vesla/room126", "east",
        "domain/original/area/vesla/room878", "north",
    });
}
