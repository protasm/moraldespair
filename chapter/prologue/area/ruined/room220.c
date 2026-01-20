inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Northern End";
    long_desc = "The way ends beneath a sagging lintel, the stones split and bowed. A scatter of fallen blocks marks the threshold into the north.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room219", "south",
        "chapter/prologue/area/ruined/room221", "west",
        "chapter/prologue/area/ruined/room233", "east",
        "chapter/prologue/area/ruined/room117", "north",
    });
}
