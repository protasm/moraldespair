inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Carriage house";
    long_desc = "Carriage house.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room915", "west",
    });
}
