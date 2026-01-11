inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Alcove";
    long_desc = "The chamber is tight and dim, its stone sweating with damp and the floor\n"
        + "cluttered with scraps of paper turned to pulp. A broken cabinet and a rusted\n"
        + "lockbox lean together in the quiet of long neglect.\n";
    dest_dir = ({
        "domain/original/area/vesla/room847", "east",
    });
}
