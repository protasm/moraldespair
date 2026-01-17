inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Bleached Broken Bend";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Fragments of\n"
                "arches and lintels hang at odd angles, cut and burned through. The passage\n"
                "angles hard here, squeezed between stone left to lean and settle. Thin lichen\n"
                "mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1600", "south",
        "domain/original/area/indel/room1604", "east",
    });
}
