inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dormant Rows";
    long_desc = "Long lines of empty sleeping frames sit rigid in the gloom, their wood\n"
                + "soft with rot. The floor is pitted and damp, and silence presses against\n"
                + "the walls.\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "north",
    });
}

