inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Withered Park";
    long_desc = "Dry shrubs crowd a cracked path, and pale trunks stand stripped of bark. Old lantern hooks hang crooked from a low wall, black with rust.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room230", "south",
        "chapter/prologue/area/ruined/room796", "west",
        "chapter/prologue/area/ruined/room228", "east",
        "chapter/prologue/area/ruined/room426", "north",
    });
}
