inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Gwyneth's bedroom";
    long_desc = "In Gwyneth's bedroom";
    dest_dir = ({
        "chapter/prologue/area/ruined/room873", "down",
        "chapter/prologue/area/ruined/room872", "up",
    });
}
