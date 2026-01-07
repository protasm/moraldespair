inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "House of Balin";
    long_desc = "House of Balin.\n";
    dest_dir = ({
        "domain/original/area/balin/room712", "west",
        "domain/original/area/balin/room654", "south",
    });
}
