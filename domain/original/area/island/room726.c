inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western District";
    long_desc = "Western District.\n";
    dest_dir = ({
        "domain/original/area/balin/room725", "east",
        "domain/original/area/balin/room727", "south",
    });
}
