inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Split Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Fragments\n"
                "of arches and lintels hang at odd angles, cut and burned through. The path\n"
                "splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen\n"
                "mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1599", "north",
        "domain/original/area/indel/room1597", "south",
        "domain/original/area/indel/room1600", "east",
    });
}
