inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "The way runs quiet between squat walls, its stones dulled and uneven. Old carvings are worn to nubs, nearly erased by weather.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room214", "south",
        "chapter/prologue/area/ruined/room216", "north",
    });
}
