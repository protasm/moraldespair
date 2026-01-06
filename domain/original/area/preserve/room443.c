inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bird Sanctuary";
    long_desc = "Bird Sanctuary.\n";
    dest_dir = ({
        "domain/original/area/preserve/room442", "east",
    });
}
