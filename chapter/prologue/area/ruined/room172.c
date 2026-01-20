inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "A broad road runs north and south, its surface worn into shallow ruts that hold dust and rain marks. Collapsed storefronts sag along the edges, their doorways open to the air.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room116", "south",
        "chapter/prologue/area/ruined/room226", "west",
        "chapter/prologue/area/ruined/room735", "east",
        "chapter/prologue/area/ruined/room173", "north",
    });
}

