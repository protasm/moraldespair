inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Dune Path";
    long_desc = "A Dune Path.\n";
    dest_dir = ({
        "domain/original/area/island/room607", "south",
        "domain/original/area/island/room609", "north",
    });
}
