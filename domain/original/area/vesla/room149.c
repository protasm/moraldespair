inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silt-Choked West River Street";
    long_desc = "The river street is cracked and half-buried beneath silt and rubble. Broken embankments and ash show where the dragons tore through.\n";
    dest_dir = ({
        "domain/original/area/vesla/room150", "east",
        "domain/original/area/vesla/room148", "west",
    });
}
