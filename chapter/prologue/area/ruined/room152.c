inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "The southern main road is rutted and split, its stones tipped at odd angles. A fallen signboard lies half buried in dust.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room151", "south",
        "chapter/prologue/area/ruined/room819", "west",
        "chapter/prologue/area/ruined/room817", "east",
        "chapter/prologue/area/ruined/room153", "north",
    });
}


