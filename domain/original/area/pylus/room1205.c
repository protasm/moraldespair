inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Pylus road";
    long_desc = "End of Pylus road.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1206", "south",
        "chapter/prologue/area/ruined/portal", "vesla",
    });
}
