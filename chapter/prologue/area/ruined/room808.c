inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Livery";
    long_desc = "Livery";
    dest_dir = ({
        "chapter/prologue/area/ruined/room809", "up",
        "chapter/prologue/area/ruined/room161", "west",
    });
}
