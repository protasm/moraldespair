inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Slick Split Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1598", "north",
        "domain/original/area/indel/room1596", "south",
        "domain/original/area/indel/room1533", "west",
    });
}
