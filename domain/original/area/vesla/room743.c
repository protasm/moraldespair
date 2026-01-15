inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hollow Counter";
    long_desc = "A cracked counter stretches across the room, with empty racks behind it.\n"
                + "Rot has crept into the floorboards, and mildew stains blur whatever\n"
                + "goods once stood here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room191", "south",
    });
}

