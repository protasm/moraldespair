inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Seamed Cold Broken Bend";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between leaning stone. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1594", "north",
        "domain/original/area/indel/room1592", "west",
    });
}
