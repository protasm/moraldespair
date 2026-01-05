inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The inner ward";
    long_desc = "The inner ward.\n";
    dest_dir = ({
        "domain/original/area/vesla/room766", "west",
        "domain/original/area/vesla/room767", "northwest",
        "domain/original/area/vesla/room758", "south",
        "domain/original/area/vesla/room757", "southwest",
        "domain/original/area/vesla/room769", "northeast",
        "domain/original/area/vesla/room770", "east",
        "domain/original/area/vesla/room768", "north",
    });
}
