inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "chapter/prologue/area/ruined/room802", "east",
        "chapter/prologue/area/ruined/room804", "south",
    });
}
