inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruined Western Gate of Vesla";
    long_desc = "The western gate lies smashed, its stones scattered across the approach. Whatever once guarded Vesla now stands as a blackened ruin.\n";
    dest_dir = ({
        "domain/original/area/vesla/room133", "east",
        "domain/original/area/roadway/room29", "exit",
    });
}
