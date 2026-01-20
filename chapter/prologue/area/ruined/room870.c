inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Rohan's bedroom";
    long_desc = "In Rohan's bedroom";
    dest_dir = ({
        "chapter/prologue/area/ruined/room869", "down",
        "chapter/prologue/area/ruined/room871", "up",
    });
}
