inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dragon's Den";
    long_desc = "Dragon's Den.\n";
    dest_dir = ({
        "domain/original/area/preserve/room499", "west",
    });
}
