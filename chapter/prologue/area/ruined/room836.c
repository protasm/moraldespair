inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Inner Sanctum";
    long_desc = "Inner Sanctum";
    dest_dir = ({
        "chapter/prologue/area/ruined/room835", "east",
    });
}
