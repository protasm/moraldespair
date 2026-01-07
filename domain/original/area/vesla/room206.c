inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken East River Street";
    long_desc = "The roadway along the river is split and sagging, choked with rubble. The embankment is broken, a scar from the dragons' wrath.\n";
    dest_dir = ({
        "domain/original/area/vesla/room205", "west",
        "domain/original/area/vesla/room207", "east",
        "domain/original/area/vesla/room397", "north",
    });
}
