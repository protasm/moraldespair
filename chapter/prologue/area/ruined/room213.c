inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Southern End";
    long_desc = "The way thins into broken stones, the once- straight line sagging. Fallen trim and damp rubble gather at the end of the road.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room212", "south",
        "chapter/prologue/area/ruined/room399", "east",
        "chapter/prologue/area/ruined/room214", "north",
    });
}
