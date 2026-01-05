inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Snake Charmer";
    long_desc = "Snake Charmer.\n";
    dest_dir = ({
        "domain/original/area/candera/room65", "west",
    });
}
