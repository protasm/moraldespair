inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "The inner ward\n";
    dest_dir = ({
        "domain/original/area/vesla/room756", "south",
        "domain/original/area/vesla/room765", "northeast",
        "domain/original/area/vesla/room758", "east",
        "domain/original/area/vesla/room766", "north",
    });
}
