inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park";
    dest_dir = ({
        "domain/original/area/vesla/room226", "south",
        "domain/original/area/vesla/room227", "west",
        "domain/original/area/vesla/room173", "east",
        "domain/original/area/vesla/room234", "north",
    });
}
