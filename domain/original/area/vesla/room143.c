inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Corner of Basalt Avenue and West River Street";
    long_desc = "The corner is buried under fused basalt and broken river stones. Dragonfire has left the ground warped and cracked.\n";
    dest_dir = ({
        "domain/original/area/vesla/room144", "east",
        "domain/original/area/vesla/room142", "north",
    });
}
