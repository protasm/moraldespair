inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Alchemist Shop";
    long_desc = "Alchemist Shop.\n";
    dest_dir = ({
        "domain/original/area/balin/room616", "west",
    });
}
