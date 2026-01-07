inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The City Gate";
    long_desc = "The City Gate.\n";
    dest_dir = ({
        "domain/original/area/island/room608", "south",
        "domain/original/area/island/room631", "west",
        "domain/original/area/island/room634", "east",
        "domain/original/area/island/room610", "north",
    });
}
