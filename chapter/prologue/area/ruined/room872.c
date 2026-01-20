inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Vella's bedroom";
    long_desc = "In Vella's bedroom";
    dest_dir = ({
        "chapter/prologue/area/ruined/room871", "down",
    });
}
