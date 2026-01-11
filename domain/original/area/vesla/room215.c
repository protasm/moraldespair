inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "The way runs quiet between squat walls, its stones dulled and uneven. Old\n"
                + "carvings are worn to nubs, nearly erased by weather.\n";
    dest_dir = ({
        "domain/original/area/vesla/room214", "south",
        "domain/original/area/vesla/room216", "north",
    });
}
