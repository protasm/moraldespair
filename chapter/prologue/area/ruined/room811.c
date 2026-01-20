inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hardware Store";
    long_desc = "Hardware Store";
    dest_dir = ({
        "chapter/prologue/area/ruined/room163", "west",
    });
}
