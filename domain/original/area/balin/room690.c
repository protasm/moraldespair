inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to the Hall of Records";
    long_desc = "Entrance to the Hall of Records.\n";
    dest_dir = ({
        "domain/original/area/balin/room617", "east",
    });
}
