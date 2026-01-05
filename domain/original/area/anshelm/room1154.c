inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Guard Post";
    long_desc = "Eastern Guard Post.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room237", "northwest",
        "domain/original/area/anshelm/room1155", "east",
    });
}
