inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Barbarian's Guild";
    long_desc = "Barbarian's Guild.\n";
    dest_dir = ({
        "domain/original/area/candera/room62", "east",
    });
}
