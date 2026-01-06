inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mariner's Revenge";
    long_desc = "Mariner's Revenge.\n";
    dest_dir = ({
        "domain/original/area/balin/room613", "west",
        "domain/original/area/balin/room677", "north",
    });
}
