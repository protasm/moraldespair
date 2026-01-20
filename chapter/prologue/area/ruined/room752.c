inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormant Rows";
    long_desc = "Long lines of empty sleeping frames sit rigid in the gloom, their wood soft with rot. The floor is pitted and damp, and silence presses against the walls.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room748", "north",
    });
}

