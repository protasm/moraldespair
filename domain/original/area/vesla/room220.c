inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Northern End";
    long_desc = "The way ends beneath a sagging lintel, the stones split and bowed. A scatter of\n"
                + "fallen blocks marks the threshold into the north.\n";
    dest_dir = ({
        "domain/original/area/vesla/room219", "south",
        "domain/original/area/vesla/room221", "west",
        "domain/original/area/vesla/room233", "east",
        "domain/original/area/vesla/room117", "north",
    });
}
