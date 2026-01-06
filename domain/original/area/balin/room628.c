inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A valley between two large dunes";
    long_desc = "A valley between two large dunes.\n";
    dest_dir = ({
        "domain/original/area/balin/room629", "east",
        "domain/original/area/balin/room607", "west",
    });
}
