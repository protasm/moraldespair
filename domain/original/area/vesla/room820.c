inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cleric Guild";
    long_desc = "Cleric Guild.\n";
    dest_dir = ({
        "domain/original/area/vesla/room839", "west",
        "domain/original/area/vesla/room153", "east",
        "domain/original/area/vesla/room838", "north",
    });
}
