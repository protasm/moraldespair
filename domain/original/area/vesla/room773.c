inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Iron Rings";
    long_desc = "Rusty ring bolts stud the posts, and the plank walls bow with age. Old\n"
                + "straw dust clings to the floor, mixed with a sour, damp rot.\n";
    dest_dir = ({
        "domain/original/area/vesla/room789", "south",
        "domain/original/area/vesla/room770", "west",
        "domain/original/area/vesla/room774", "east",
        "domain/original/area/vesla/room788", "north",
    });
}

