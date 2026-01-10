inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle stables";
    long_desc = "Castle stables";
    dest_dir = ({
        "domain/original/area/vesla/room790", "south",
        "domain/original/area/vesla/room765", "west",
        "domain/original/area/vesla/room773", "east",
        "domain/original/area/vesla/room791", "north",
    });
}
