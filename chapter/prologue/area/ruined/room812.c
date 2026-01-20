inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Haseltine Engravers";
    long_desc = "Haseltine Engravers";
    dest_dir = ({
        "chapter/prologue/area/ruined/room164", "west",
    });
}
