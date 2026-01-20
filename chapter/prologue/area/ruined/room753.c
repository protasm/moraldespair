inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hinged Span";
    long_desc = "A hinged span lies open over the gap, its timbers split and softened by rot. Rusty chains sag from the ruined fittings, and the stone landing is scoured bare.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room169", "southwest",
        "chapter/prologue/area/ruined/room754", "north",
    });
}

