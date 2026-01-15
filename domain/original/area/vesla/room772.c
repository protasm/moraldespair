inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ash Store";
    long_desc = "Low shelves and bins crowd the room, warped and split from damp. Cinder\n"
                + "stains and rusted nail heads hint at the forge work once stacked here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room771", "west",
    });
}

