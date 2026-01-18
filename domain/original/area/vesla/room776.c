inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cracked Trough";
    long_desc = "A stone trough is split down the middle, its basin crusted with lime. Rot has eaten the surrounding planks, leaving gaps filled with dust and mold.";
    dest_dir = ({
        "domain/original/area/vesla/room782", "south",
        "domain/original/area/vesla/room775", "west",
        "domain/original/area/vesla/room777", "east",
        "domain/original/area/vesla/room781", "north",
    });
}

