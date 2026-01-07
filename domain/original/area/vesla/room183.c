inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Breached Wall Road";
    long_desc = "The city wall is broken here, its stones strewn across the street. The wall-side street is a rubble-strewn trench running along the shattered defenses.\n";
    dest_dir = ({
        "domain/original/area/vesla/room182", "east",
        "domain/original/area/vesla/room184", "west",
    });
}

void init() {
    ::init();
    add_action("block_structure", "west");
}

int block_structure() {
    write("Only rubble remains there; the way is impassable.\n");
    return 1;
}
