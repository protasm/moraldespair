inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Main Road";
    long_desc = "The main road bends toward the gate, its stones worn thin and pale. A line of\n"
              + "old posts leans toward the center.\n";
    dest_dir = ({
        "domain/original/area/vesla/room166", "south",
        "domain/original/area/vesla/room168", "north",
    });
}
