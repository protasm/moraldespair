inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Druids Guild";
    long_desc = "Druids Guild.\n";
    dest_dir = ({
        "domain/original/area/forest/room578", "west",
    });
}
