inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park\n";
    dest_dir = ({
        "domain/original/area/vesla/room230", "south",
        "domain/original/area/vesla/room796", "west",
        "domain/original/area/vesla/room227", "east",
        "domain/original/area/vesla/room426", "north",
    });
}
