inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mariner's Revenge";
    long_desc = "Mariner's Revenge.\n";
    dest_dir = ({
        "domain/original/area/island/room613", "west",
        "domain/original/area/island/room677", "north",
    });
}
