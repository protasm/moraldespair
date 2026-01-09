inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Breached Eastern End of the Wall Road";
    long_desc = "The city wall is broken here, its stones strewn across the "
        + "street. The wall-side street is a rubble-strewn trench running"
        + " along the shattered defenses.\n";
    dest_dir = ({
        "domain/original/area/vesla/room180", "east",
        "domain/original/area/vesla/room182", "west",
    });
}
