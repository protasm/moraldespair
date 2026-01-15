inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hinged Span";
    long_desc = "A hinged span lies open over the gap, its timbers split and softened by\n"
                + "rot. Rusty chains sag from the ruined fittings, and the stone landing is\n"
                + "scoured bare.\n";
    dest_dir = ({
        "domain/original/area/vesla/room169", "southwest",
        "domain/original/area/vesla/room754", "north",
    });
}

