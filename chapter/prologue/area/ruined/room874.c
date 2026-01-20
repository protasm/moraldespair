inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bottom floor of the silo";
    long_desc = "Bottom floor of the silo";
    dest_dir = ({
        "chapter/prologue/area/ruined/room873", "up",
    });
}
