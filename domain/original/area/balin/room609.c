inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The City Gate";
    long_desc = "The City Gate.\n";
    dest_dir = ({
        "domain/original/area/balin/room608", "south",
        "domain/original/area/balin/room631", "west",
        "domain/original/area/balin/room634", "east",
        "domain/original/area/balin/room610", "north",
    });
}
