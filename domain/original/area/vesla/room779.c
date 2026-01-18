inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Empty Stalls";
    long_desc = "Stall partitions linger as gray ribs, and rusted hinges hang from them. The floor is packed hard and bare, with only the stink of wet rot left.";
    dest_dir = ({
        "domain/original/area/vesla/room783", "west",
        "domain/original/area/vesla/room777", "northwest",
        "domain/original/area/vesla/room778", "north",
    });
}

