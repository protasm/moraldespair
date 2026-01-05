inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Science laboratory";
    long_desc = "Science laboratory.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room904", "east",
    });
}
