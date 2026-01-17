inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Split Cold Broken Bend";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and\n"
                "hollows. Fragments of arches and lintels hang at odd angles, cut and burned\n"
                "through.\n"
                "\n"
                "The passage angles hard here, squeezed between stone left to lean and settle.\n"
                "Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1600", "north",
        "domain/original/area/indel/room1605", "east",
    });
}
