inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sooted Shop";
    long_desc = "Soot smears the walls above a narrow counter, and empty hooks line the back. A crust of old oil darkens the floorboards, now gritty with dust and ash.";
    dest_dir = ({
        "domain/original/area/vesla/room121", "south",
    });
}


