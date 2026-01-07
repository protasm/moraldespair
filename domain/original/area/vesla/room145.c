inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silt-Choked West River Street";
    long_desc = "The river street is cracked and half-buried beneath silt and rubble. Broken embankments and ash show where the dragons tore through.\n";
    dest_dir = ({
        "domain/original/area/vesla/room146", "east",
        "domain/original/area/vesla/room144", "west",
    });
}
