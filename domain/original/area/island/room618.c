inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = "Silver Street.\n";
    dest_dir = ({
        "domain/original/area/island/room617", "south",
        "domain/original/area/island/room622", "west",
        "domain/original/area/island/room691", "east",
        "domain/original/area/island/room619", "north",
    });
}
